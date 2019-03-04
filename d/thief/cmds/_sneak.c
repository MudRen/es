////#pragma save_binary

#include <mudlib.h>
inherit DAEMON;
int sneak_idle(object me,int succeed,string dir,string exit)
{
	string func;
	if ( (func = (string)environment(me)->query("pre_exit_func/"+dir)) && 
		call_other(environment(me),func) ) {
		me->delete_temp("block_command");
		return 1;
	}
	if ( succeed ) {
		me->set_temp("hidding",1);
		me->move_player(exit,"SNEAK");
		me->delete_temp("block_command");
		me->set_temp("hidding",0);
	} else {
		me->move_player(exit,"",dir);
        	this_player()->block_attack(4);
        	this_player()->set_temp("msg_stop_attack",
        	"( ��Ǳ��ʧ�ܣ�������ͻϮ��һ����æ���ң� )\n" );
		call_out("sneak_done",2,me);
   	}	
	return 1;
}

int sneak_done(object me)
{
	me->delete_temp("block_command");
	return 1;
}
int check_sneak(object me)
{
	int skill;
	skill = (int)me->query_skill("sneak") ;
	if ( ! skill ) return 0;
//	if ( ! nullp(me->query_current_attacker()) ) return 0;
	skill += (10 + (int)me->query("thief_level/backstab")/2);
   	if ( skill > random(140) )
   		return 1;
   	else
   		return 0;
}
int cmd_sneak(string arg)
{
	string exit;
	mapping door;
	int delay;
	object env;

	env = environment(this_player()) ;

	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("���������������� ...\n");
	if ( this_player()->query("conditions/confused") )
                return notify_fail(set_color("���������һ�Ż��ң�������ʲ�᲻֪���Ķ����ڿС�����...\n","HIM"));
	if ( ! arg ) return notify_fail("��Ҫ������Ǳ�У�\n");
	if ( !exit = env->query("exits/"+arg) )
		return notify_fail("����û���κγ�·��\n");
	if ( door = env->query("doors/"+arg) )
		if ( (string)env->query("doors/"+arg+"/status") != "open" )
			return notify_fail("������Ź��������봩��ȥ��\n");
	/*
	if ( ! nullp(this_player()->query_current_attacker()) )
		return notify_fail("�㻹��ս����, �޷�Ǳ�С�");
	*/
	write(set_color(sprintf("�㿪ʼ��%sǱ�� ...\n",
			to_chinese(arg)),"HIY"));
/*  	��Ȼ��Ǳ��, Ӧ�ò����Ҷ�֪����.
	tell_room(env,
		sprintf("%s��ʼ��%sǱ�� ...\n",this_player()->query("c_name"),
			to_chinese(arg)),this_player());
*/
	this_player()->block_attack(4);
	delay = 2 + random(4);
	this_player()->set_temp("hidding",0);
	this_player()->set_temp("next_action",time()+delay);
	this_player()->set_temp("block_command",1);
	call_out("sneak_idle",delay,this_player(),check_sneak(this_player()),
			arg,exit );	
	return 1;
}

int help()
{
	write (@HELP
Usage: sneak <dir>

���ָ����ʹ�����ø��ֵ��Σ����ص��������ķ����ƶ������������
�ڱ��˺���֪����������ƶ��������ڵ�λ�ã���Ȼ���е��ѣ�����ֻ
Ҫ�ɹ�\�ˣ����͸������ܲ����Ĵ��ڡ�

HELP
);
	return 1;
}
