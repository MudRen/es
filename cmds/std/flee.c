// _flee.c
// Elon@ES 4-22-95

#include <mudlib.h>

inherit DAEMON;

int cmd_flee()
{
	write("ֱ���ܾͺ���!!!!!!!\n");
	return 1;
}

int help()
{
	write(@TEXT
flee - û�õ�ָ��.
TEXT
	);
}
