#include <mudlib.h>

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	
	set("light", 1);
	set_short( "长廊" );
	set_long( @LONG
这是一条宽敞的地下走廊，里面空荡荡的。
LONG
	);

	set("exits", ([
		"up" : "/d/thief/hall/thief_guild",
//		"south" : "/d/thief/hall/backstab_room2",
	]) );
	reset();
}

