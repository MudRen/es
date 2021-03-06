
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "道路" );
	set_long( @LONG_DESCRIPTION
你现在正走在一条碎石铺成的道路上，道路向东、西方向延伸。路旁的草
地上长著一些不知名的野花及野草。
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/11,9.erosmia", 
		"east"	: "/d/erosmia/12,10.erosmia", 
		"west"	: "/d/erosmia/ekravia/east_gate",
		"south"	: "/d/erosmia/11,11.erosmia",
		]) );
	set( "original", "d/erosmia/10,11" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 10 );
	reset();
}
