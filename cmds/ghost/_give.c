//#pragma save_binary
 
//	File	:  /cmds/ghost/_give.c
//	Creator	:  Watcher@TMI  (4/11/93)

//
//	Yet another Ghost filler command

#include <mudlib.h>

inherit DAEMON ;
 
int cmd_give()
{
	write( can_read_chinese()?
		"���Ѿ����ˣ�����ʲ��Ҳû�С�\n":
		"Alas, as a ghost, you have nothing to give.\n");
	return 1;
}
 
