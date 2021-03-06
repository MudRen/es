// File: 8,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("东村口");
	set_long( @LONG_DESCRIPTION
往西就是谪仙岛正中央的映世村了，映世村是位在一个略成圆形的小
丘上，丘的东北、东南、西北、西南四个方向各有一个水流出口，水源似
乎来自地底，当然它们就是岛上四条小溪的源头，如果你要进村的话可以
沿石阶而上，而打这儿往东是一片高耸的树林，那儿是传说中魔族津鸣城
所在的地方。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"westup"  : ITOWN"town07", 
		"east"  : ISLAND"9,7.island",
		]) );
	set( "original", ISLAND"8,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
