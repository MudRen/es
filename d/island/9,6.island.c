// File: 9,6.island.c

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
		"west"  : ISLAND"8,6.island", 
		"north" : ISLAND"9,5.island", 
		"east"  : ISLAND"10,6.island",
		"south" : ISLAND"9,7.island",
		]) );
	set( "original", ISLAND"9,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 6 );
        set( "no_monster" , 1 );
        set( "objects",([
                 "c1":IMON"spec_crow",
                 "c2":IMON"spec_crow"
                     ] ));
	reset();
}

