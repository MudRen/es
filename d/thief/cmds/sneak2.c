//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int sneak_idle(object me,int succeed,string dir,string exit)
{
	string func;
	if ( (func = (string)environment(me)->query("pre_exit_func/"+dir)) && 
		call_other(environment(me),func) ) {
		me->set_temp("sneaked",0);
		return 1;
	}
	if ( succeed ) {
		me->set_temp("hidding",1);
		me->move_player(exit,"SNEAK");
		me->set_temp("block_command",1);
		me->set_temp("hidding",0);
		call_out("sneak_done",2,me);
		}
	else {
		me->move_player(exit,"",dir);
        	this_player()->block_attack(4);
        	this_player()->set_temp("msg_stop_attack",
        	"( ��Ǳ��ʧ�ܣ�������ͻϮ��һ����æ���ң� )\n" );
   	}	
	me->set_temp("sneaked",0);
//	me->set_temp("block_command",0);
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
//	skill += me->query_stat("kar") ;
	skill += 20 ;
   	if (random(140) < skill)
   		return 1;
   	else
   		return 0;
}
int cmd_sneak(string arg)
{
	string exit;
	mapping door;
	object env;

	env = environment(this_player()) ;
	if ( this_player()->query_temp("sneaked") )
		return notify_fail("������Ŭ��Ǳ���� ...\n");
	if ( this_player()->query_temp("hidden") || 
	 	 this_player()->query_temp("backstabed") )
	 	 return notify_fail("������������� ... \n");
	if ( ! arg ) return notify_fail("��Ҫ������Ǳ�У�\n");
	if ( !exit = env->query("exits/"+arg) )
		return notify_fail("����û���κγ�·��\n");
	if ( door = env->query("doors/"+arg) )
		if ( (string)env->query("doors/"+arg+"/status") != "open" )
			return notify_fail("������Ź��������봩��ȥ��\n");

	write(set_color(sprintf("�㿪ʼ��%sǱ�� ...\n",
			to_chinese(arg)),"HIY"));
	tell_room(env,
		sprintf("%s��ʼ��%sǱ�� ...\n",this_player()->query("c_name"),
			to_chinese(arg)),this_player());

	this_player()->set_temp("sneaked",1);
//	this_player()->set_temp("block_command",1);
	call_out("sneak_idle",4,this_player(),check_sneak(this_player()),
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
