//#pragma save_binary
 
//	File	:  /cmds/ghost/_inventory.c
//	Creator	:  Watcher@TMI  (4/11/93)
//
//	Yet another filler ghost command.

#include <mudlib.h>
 
inherit DAEMON ;
 
int cmd_inventory()
{
	write( can_read_chinese()?
		"���Ѿ����ˣ���Щ����֮�����������������ȥ�������˰ɡ�\n":
		"You are a ghost ... you have nothing in your possession.\n");
	return 1;
}
 
