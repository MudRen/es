// File: 6,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("西村口");
	set_long( @LONG_DESCRIPTION
往东就是谪仙岛正中央的映世村了，映世村是位在一个略成圆形的小
丘上，丘的东北、东南、西北、西南四个方向各有一个水流出口，水源似
乎来自地底，当然它们就是岛上四条小溪的源头，如果你要进村的话可以
沿石阶而上，而从这往西是起伏不定的小丘陵，那是属於武士堡的势力领
域。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,7.island", 
		"eastup"  : ITOWN"town03",
		]) );
	set( "original", ISLAND"6,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
