// File: 8,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("桃花林");
	set_long( @LONG_DESCRIPTION
你身处在一片美丽的桃花林中，这里正是所谓的『落英缤纷，芳草鲜
美』，要是仔细观察此处的桃树，你会发现它们以某种巧妙的次序排列著
，但你又看不出有人力斧凿的痕迹，或许是浑然天成的吧；在这里站的越
久，你越觉得世间的名利斗争已经离你远去，这种心旷神怡的感觉，使你
对这儿流连忘返。	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"7,5.island", 
		"north" : ISLAND"8,4.island", 
		"east"  : ISLAND"9,5.island",
		"south" : ISLAND"8,6.island",
		]) );
	set( "original", ISLAND"8,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}
