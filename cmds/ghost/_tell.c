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
		"�����ڵ�״̬û���㹻����������ѶϢ���κ��ˣ������Ҫ����\n"
		"��ʽ�� bug ������ wizcall ָ�\n":
		"As a ghost, you do not have the strength to tell anyone.\n"
		"If it is an error report, you may use the \"wizcall\" command.\n");
	return 1;
}

