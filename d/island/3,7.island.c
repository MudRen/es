// File: 3,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("车马道");
	set_long( @LONG_DESCRIPTION
这是蜿蜒在丘陵之中的道路，其实也不是刻意铺出来的，而是来往人
马将地面上踏出一条小路，路是人走出来的，这话还真是没错；这小路是
东西向的，到这就到目的地了，在你西边的是宏伟的武士堡！快进去吧！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : "/d/island/samurai/room/station", 
		"north" : ISLAND"3,6.island", 
		"east"  : ISLAND"4,7.island",
		"south" : ISLAND"3,8.island",
		]) );
	set( "original", ISLAND"3,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 3 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

