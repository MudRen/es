
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "山丘小径" );
	set_long( @LONG_DESCRIPTION
你走在低矮的山丘上, 周围是美丽的草原与花朵。东方的山脚下可以
望见一个美丽的城镇。从那边, 一条小径蜿蜒而来, 横过你的面前, 连往
西边的山中。
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/9,9.erosmia", 
		"east"	: "/d/erosmia/ekravia/west_gate", 
//		"west"	: "/d/erosmia/8,10.erosmia",
		"south"	: "/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/9,10" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 10 );
	reset();
}
