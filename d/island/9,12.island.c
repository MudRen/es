// File: 9,12.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("浅海");
	set_long( @LONG_DESCRIPTION
这儿是靠近岸边的的浅海，虽然深浅不一，但总在10公尺以内，海是
很危险的，随时要注意自己的身体状况，不要硬撑；唷！对了，这儿常有
暗潮，不小心可能会被冲得很远。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,12.island",
		"north" : ISLAND"9,11.island",
		]) );
	set( "original", ISLAND"9,12" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 12 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
