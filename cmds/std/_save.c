//#pragma save_binary

// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Written by Sulam(12-13-91)
// Help?? added by Brian on that most wonderful of days (1/28/92)

#include <mudlib.h>

inherit DAEMON;

int cmd_save(string str)
{
	object link ;
	this_player()->save_me();
	link = this_player()->query_link() ;
	if (link) link->save_data() ;
	write( 
		this_player()->query("c_name")+"���ϴ浵....��ϡ�\n");

	return 1;
}

int help() {
	write(@HELP
Syntax: save

�����������.
�����ж�ʱ�����û����Ϲ��ܣ���Ϊ��ȫ���������������ʱsave.
HELP
);
	return 1;
}
/* EOF */
