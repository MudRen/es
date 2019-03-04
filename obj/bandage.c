// bandage.c
// Rewritten by Annihilator to fit the new recover system (09-21-94)
// add exp gain for healers by indra 11.30.94
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
#include <compress_obj.h>
	set_name( "bandage", "����" );
	set_short("����" );
	set_long(
		"������һ�ֳ����ġ�����ʹ���˵��˼ӿ�ָ��ٶȵ�ҽҩ��Ʒ�����\n"
		"��ѧ���˿ڰ����ļ��ܣ��Ϳ����� bandage ָ�����Լ�����˰�����\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 15, "silver" }) );
}

void init()
{
	add_action("do_bandage", "bandage");
	add_action("do_remove", "remove" );
}

int do_bandage(string arg)
{
	object dest;
	int skill, pie;
	mixed *cond; 

	// The player must carry the bandage before he can bandage.
	if( environment()!=this_player() ) return 0;

	if( query("in_use") ) return notify_fail("�������Ѿ���ʹ�����ˡ�\n");
				
	if( !arg || arg=="me" || arg=="myself" ) dest = this_player();
	else dest = present( arg, environment(this_player()) );
	if( !dest )
		return notify_fail("��Ҫ����˭��\n");

	if( (int)dest->query_temp("bandaged") >= time()) {
		write("�����Ҫ���°��������ȳ�ȥ(remove)ԭ���ı�����\n");
		return 1;
	}

	if( dest->query("hit_points")==dest->query("max_hp") ) {
		write("����ֻ�������������˵��ˡ�\n");
		return 1;
	}
	
	// Ok, now do the bandage stuff.
	if( dest==this_player()) {
		write("��ϸ�ĵ�Ϊ�Լ����˿ڰ��ϱ�����\n");
		tell_room( environment(this_player()), 
			sprintf("%s�ñ��������Լ����˿ڡ�\n",this_player()->query("c_name")),
			this_player() );
	} else {
		write(sprintf("��ϸ�ĵ��ñ�����%s�����˿ڡ�\n",dest->query("c_name")));
		tell_object( dest,
			sprintf("%s�ñ�����������˿ڡ�\n",this_player()->query("c_name")));
		tell_room( environment(this_player()), 
			sprintf("%s�ñ�����%s�����˿ڡ�\n",this_player()->query("c_name"),dest->query("c_name")),
			({ dest, this_player() }) );
		move(dest);
	}
	
	skill = this_player()->query_skill("bandage");
	pie = dest->query_stat("pie");
	cond = dest->query("conditions/herb_apply");
	if( cond && sizeof(cond) ) {
		// speed up �� 0% �� 80%, when skill 0 �� 100, by Kyoko/Annihilator.
		cond[0] -= cond[0] * skill * 8 / 1000;
		if( cond[0] < 1 ) cond[0] = 1;
		dest->set("conditions/herb_apply", cond);
	}
	BANDAGED->apply_effect(dest, 12-skill*84/1000);
	dest->set_temp("bandaged",time()+50+skill+3*pie);
	set( "in_use", 1 );
	set( "prevent_drop", 1 );
	set( "prevent_insert", 1 );
	set_short( "���� (ʹ����)" );

        // add this part to exp gain for healers
        if((string)this_player()->query("class")=="healer")
             this_player()->gain_experience(skill/5) ;

	// The bandage falls down takes a longer time than its effect.
	call_out("expire", 50+skill+3*pie);
	return 1;
}

int do_remove(string arg)
{
	object ob;
	
	ob = environment(this_object());	
	// for fix the bug of user quit or suicide.
	if( ob && living(ob) ) {
		if( !id(arg) || !query("in_use") ) return 0;
		tell_object(ob,"�㽫����������������\n");
		ob->delete_temp("bandaged");
		BANDAGED->remove_effect(ob);
		// remove the herb apply effect.
//		if( ob->query("conditions/herb_apply") )
//			HERB_APPLY->remove_effect(ob);
	}
	remove_call_out("expire");
	remove();
	return 1;
}

void expire()
{
	object ob;
	
	ob = environment();
	if( !ob || !living(ob) ) {
		remove();
		return;
	}
	tell_object(ob,"��ı�������Ѫ��͸�ˡ�\n");
	do_remove("bandage");
	return;
}
