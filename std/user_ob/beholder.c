// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/beholder";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Beholder.
	beholder::setup_race_body();
	add_action("do_gaze","gaze");
}

int do_gaze()
{
        object victim ;
        if ( !victim = query_attacker())
                return notify_fail("������ֲ���ս���У��� look �ͺ��ˡ�\n");

        if ( query_temp("gazing") )
                return notify_fail("����ר��������ĵ��� ... \n");

        if ( victim->query("stop_attack") ) 
                return notify_fail("�� ! ��׷������ˣ����Ѿ�˯���ˡ�\n");

	tell_object(this_object(),"�������ħ��ר������������ ...\n");

	tell_object(victim,sprintf("%s�����������ħ���������㣬��ͻȻ�е�ǿ�ҵ�˯�⡣\n",query("c_name")));

        tell_room(environment(this_object()),
                  sprintf("%s����������۾�������%s��\n",query("c_name"),
                          victim->query("c_name")),({ this_object(),victim }));

        set_temp("gazing",1);
        call_out("sleeping",4,this_object(),victim);
        return 1;
}


void sleeping(object me,object victim)
{
	me->set_temp("gazing",0);
	if ( !me || !victim ) return;
        if ( !me->query_attacker() ) return ;
        if ( random((int)victim->query_level()*4) > (int)me->query_level() ) {
                tell_object(me,set_color("���ǵ��˲��ϵ� ...\n","HIC",me));
                tell_object(victim,"��ƴ���Ĵ�����˵��˯���ǲ�˯��\n");
                return;
	}
        victim->block_attack(4);
	victim->set_temp("msg_stop_attack",
                "( ������˯��������� )\n" );
        tell_object(me,set_color("���˿�ʼ������ ...\n","HIY",me));
        return ;
}