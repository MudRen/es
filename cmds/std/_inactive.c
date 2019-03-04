//#pragma save_binary
 
//	File	:  /cmds/std/_inactive.c
//	Created :  Watcher@TMI  (09/27/92)
//
//	Command to toggle user inactive mode.
 
#include <mudlib.h>

inherit DAEMON;

int cmd_inactive()
{
	object me;

	me = this_player();
	write("�������ͣ�. �밴 [ENTER] �Լ����.\n");
	tell_room(environment(me), 
		sprintf("%s(%s)������ʱֹͣ���\n", me->query("c_name"),
			me->query("name")) , me);

	me->set("inactive", time());
 
	input_to("stop_inactive", 1);

	return 1;
}

int stop_inactive()
{
	object me;

	me = this_player();
	printf("����ֹͣ� %s ���ֿ�ʼ�.\n",
		format_time(time()-(int)me->query("inactive"), 1));
	tell_room(environment(me), 
		sprintf("%s(%s)�ֿ�ʼ���»�ˡ�\n", me->query("c_name"),
			me->query("name")) , me);
	me->delete("inactive");
	return 1;
}
 
int help()
{
	write(@HELP

���ָ��ʹ�㴦��ֹͣ����״̬.

HELP
);
	return 1;
}

// Prevent cleanup.
int clean_up()
{
	return 1;
}
