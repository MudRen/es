// File: 11,8.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("树海");
	set_long( @LONG_DESCRIPTION
这是一片由高耸入云的巨木所构成的树海，由於树木很密，致使你几
乎看不到树林深处有什麽存在，也因此这里从以前就有很多神秘的传说。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"10,8.island", 
		"north" : ISLAND"11,7.island", 
		"east"  : ISLAND"12,8.island",
		"south" : ISLAND"11,9.island",
		]) );
	set( "original", ISLAND"11,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}

