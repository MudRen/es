#include <mudlib.h>

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	
	set("light", 1);
	set_short( "����" );
	set_long( @LONG
����һ�����ĵ������ȣ�����յ����ġ�
LONG
	);

	set("exits", ([
		"up" : "/d/thief/hall/thief_guild",
//		"south" : "/d/thief/hall/backstab_room2",
	]) );
	reset();
}

