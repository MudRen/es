//#pragma save_binary

// uptime.c
// Tells you how long the mud is up.
// Lord knows who wrote it.
// Mobydick added header and help, 11-20-92

#include <mudlib.h>
#include <reboot.h>

inherit DAEMON;

int cmd_uptime()
{
	printf("���������Ѿ�����ִ���� %s��\n", format_c_time(uptime(), 1));

	if( REBOOT_DELAY-uptime() > 0 )
	printf("�� Reboot ���� %s��\n",format_c_time(REBOOT_DELAY-uptime(), 1) );
	else
	  this_player()->quick_message("�Ѿ����� Reboot ������ʱ�ˡ�\n" );
	return 1;
}

int help()
{
	write (@HELP
ʹ�ø�ʽ: uptime

��ʾ��Ϸ�Ѿ����ж���ʱ��.
HELP
);
	return 1;
}
