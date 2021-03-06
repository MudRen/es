// File: 7,10.island.c

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
，你想你对於蜥蜴人的智商要重新评估了；这不甚美观但是很实用的道路
是南北向的，它通往蜥蜴人的居所，走在上面要小心别把衣服弄脏了。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,10.island", 
		"north" : ISLAND"7,9.island", 
		"east"  : ISLAND"8,10.island",
		"south" : ISLAND"7,11.island",
		]) );
	set( "original", ISLAND"7,10" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 10 );
	set( "objects",([ "feller" : "/d/island/hole/monster/feller" ]) );
	reset();
}

