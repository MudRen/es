// /d/ocean/ocean.c

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "�շ���");
	set_long(
		"This is a simple room created by roommaker.\n",
		"����һ���÷���༭��������Ŀշ��䡣\n"
	);
}
