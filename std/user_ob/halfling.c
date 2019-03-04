// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/halfling";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Halfling.
	halfling::setup_race_body();
	modify_skill("trading",query_level()*2);
	add_action("do_joke","joke");
}

int do_joke()
{
	string laugh,*action = ({ "%sָ��%s�ı���Ц��ֱ����������\n", 
			"%s��%s������������ȥ���ô󶦡���������\n", 
			"%sװ��һ������С����ӣ�����%sҡͷ���ԡ�\n", 
			"%sһƨ�����ڵ��ϣ�ָ��%s���������Ŀ���������\n",
			"%s�������Ϳ%s������\n" }) ;
	object victim ;
	if ( !victim = query_attacker())
		return notify_fail("���ˣ�������ֲ���ս���С�\n");

        if ( query_temp("joking") )
                return notify_fail("������Ŭ��ˣ���� ... \n");
    if( query_temp("busy") )
    	return notify_fail("\n  ������ר����������飬���ܷ���ˣ����\n");
	if ( victim->query("stop_attack") || 
		(int)victim->query_temp("be_joke")==3 )
		return notify_fail("�� ! ��׷������ˣ������ڿɲ����ϵ��ˡ�\n");

        laugh = action[random(5)];

	tell_object(this_object(),"���������Ŭ����ˣ�� ...\n");

	tell_object(victim,sprintf(laugh,query("c_name"),"��"));

	tell_room(environment(this_object()),
		  sprintf(laugh,query("c_name"),
			  victim->query("c_name")),({ this_object(),victim }));

	set_temp("joking",1);
	set_temp("busy",1);
	call_out("funny",2,this_object(),victim);
	return 1;
}

void funny(object me,object victim)
{
	int i;
	me->set_temp("joking",0);
	me->delete_temp("busy");

	if ( !me->query_attacker() || !victim || nullp(victim) ) return ;
        i=7+victim->query_perm_stat("int")-me->query_perm_stat("int");
	i=i/10;
        if (i < 0) i = 0;
	if ( random(3) < (i+(int)victim->query_temp("be_joke")) ) {
		tell_object(me,set_color("���ǵ��˲�Ϊ���� ...\n","HIC",me));
		tell_object(victim,"��ƴ������סЦ�������ϵ���\n");
		return;
	}
        victim->block_attack(4);
	victim->set_temp("msg_stop_attack",
		"( ������Ц�û���û�����޷������� )\n" );
	victim->add_temp("be_joke",1);
	tell_object(me,set_color("����Ц��ֱ�����������û��� ...\n","HIY",me));
	return ;
}
