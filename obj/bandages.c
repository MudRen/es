// bandages.c
// Rewritten by Yueh from bandage.c (1-2-96)
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
#include <compress_obj.h>
	set_name( "bandages", "������" );
	set_short("������" );
	set_long(
		"������һ�ֳ����ġ�����ʹ���˵��˼ӿ�ָ��ٶȵ�ҽҩ��Ʒ������\n"
		"���ɰ�����Ρ�������� bandage ָ�����Լ�����˰�����\n"
	);
	set( "unit", "��" );
	set( "weight", 25 );
	set("left",5);
	set( "value", ({ 75, "silver" }) );
}

void init()
{
	add_action("do_bandage", "bandage");
}

int do_bandage(string arg)
{
	object dest,ban;
	int skill, pie, left;
	mixed *cond; 

	// The player must carry the bandage before he can bandage.
	if( environment()!=this_player() ) return 0;
	
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
		write("��ӱ�����˺��һ�α���ϸ�ĵ�Ϊ�Լ����˿ڰ�����\n");
		tell_room( environment(this_player()), 
			sprintf("%s�ñ��������Լ����˿ڡ�\n",this_player()->query("c_name")),
			this_player() );
	} else {
		write(sprintf("��ӱ�����˺��һ�α���ϸ�ĵ���%s�����˿ڡ�\n",dest->query("c_name")));
		tell_object( dest,
			sprintf("%s�ñ�����������˿ڡ�\n",this_player()->query("c_name")));
		tell_room( environment(this_player()), 
			sprintf("%s�ñ�����%s�����˿ڡ�\n",this_player()->query("c_name"),dest->query("c_name")),
			({ dest, this_player() }) );
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

	ban=new("/obj/bandage_used");
	ban->set_fuel(50+skill+3*pie);
	this_player()->add("load",-5);
	set("weight",query("weight")-5);
	ban->move(dest);
        // add this part to exp gain for healers
        if((string)this_player()->query("class")=="healer")
             this_player()->gain_experience(skill/5) ;
	left=query("left")-1;
	if (left== 0) {
		write("�������������ˣ������ְ���������\n");
		remove();
	}
	else set("left",left);
	return 1;
}

