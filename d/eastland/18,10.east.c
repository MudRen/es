// File: /d/eastland/18,10.east.c
// Generated by Roommaker Sat Jan 22 04:46:36 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "沙滩");
	set_long( @LONG_DESCRIPTION
你现在来到了海边的沙滩上，一望无际的大海在远处和碧蓝的天空相接，使
人忘却了烦恼。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
		"south" : "d/eastland/18,11.east" ]) );
	set( "original", "d/eastland/18,10" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
	set( "x_coordinate", 18 );
	set( "y_coordinate", 10 );
	reset();
#include <replace_room.h>
}
void init()
{
  if(!find_object("/d/island/island_gate"))
  {
    "/d/island/island_gate"->frog();
  }
}
