// File: 7,11.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("芦苇便道");
	set_long( @LONG_DESCRIPTION
在沼泽中造路是很不容易的，蜥蜴人想出了好方法，将石头以草绳绑
住，然後填在沼泽中，并在两旁种植芦苇，以保护路基，看了这条路以後
，你想你对於蜥蜴人的智商要重新评估了；这道路到这儿往南通往一个岩
石平台，那儿好像是蜥蜴人洞穴的入口，你想你应该小心点唷，蜥蜴人并
不好惹啊！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,11.island", 
		"north" : ISLAND"7,10.island", 
		"east"  : ISLAND"8,11.island",
		"south" : ISLAND"7,12.island",
		]) );
	set( "original", ISLAND"7,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 11 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

