// File: 11,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("林荫道");
	set_long( @LONG_DESCRIPTION
这位在森林中的道路是魔族所造的，由石板铺成的路面，笔直的在树
林中穿过，两旁的树木正好把阳光滤掉，走在这儿你觉得十分凉爽；东西
向的林荫道，到这儿就停了，再往东有个小湖，看来不像有城堡的样子，
看来要到津鸣城要费一番工夫了！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"10,7.island", 
		"north" : ISLAND"11,6.island", 
		"east"  : "/d/island/forest/area/start",
		"south" : ISLAND"11,8.island",
		]) );
	set( "original", ISLAND"11,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
