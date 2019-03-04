//#pragma save_binary
 
//	File	:  /cmds/ghost/_tell.c
//	Creator	:  Watcher@TMI  (04/03/93)
//
//	Just a filler tell command for the ghosts.

#include <mudlib.h>

inherit DAEMON ;
 
int cmd_tell()
{
	write( can_read_chinese()?
		"你现在的状态没有足够的能力传达讯息给任何人，如果你要报告\n"
		"程式的 bug ，请用 wizcall 指令。\n":
		"As a ghost, you do not have the strength to tell anyone.\n"
		"If it is an error report, you may use the \"wizcall\" command.\n");
	return 1;
}

