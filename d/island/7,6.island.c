// File: 7,6.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("北村口");
	set_long( @LONG_DESCRIPTION
往南就是谪仙岛正中央的映世村了，映世村是位在一个略成圆形的小
丘上，丘的东北、东南、西北、西南四个方向各有一个水流出口，水源似
乎来自地底，当然它们就是岛上四条小溪的源头，如果你要进村的话可以
沿石阶而上，而从这往北是一片桃花林，路不太明显，请小心。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"7,5.island", 
		"southup" : ITOWN"town01",
		]) );
	set( "original", ISLAND"7,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 6 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
