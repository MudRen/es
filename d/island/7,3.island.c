// File: 7,3.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("桃林小径");
	set_long( @LONG_DESCRIPTION
这是蜿蜒在桃花林中的泥土小径，路上布满了落下来的桃花，清新的
空气加上悦耳的鸟鸣，还有两旁的桃花林，使走在这儿成了最佳享受；这
小径一路由村口往北到这就消失了，由这往北还是桃花林，不同的是好像
密了些，有些古怪，过去瞧瞧吧！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,3.island", 
		"north" : ISLAND"7,2.island", 
		"east"  : ISLAND"8,3.island",
		"south" : ISLAND"7,4.island",
		]) );
	set( "original", ISLAND"7,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 3 );
	reset();
#include <replace_room.h>
}
