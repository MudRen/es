
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "平原" );
	set_long( @LONG_DESCRIPTION
你现在走在一片平地上，疏落的青草点缀著一些碎石，这里开阔的视
野使你可以清楚地看到远方的景物。
    南边不远处可以看到一座繁华的城镇, 一道低矮的围墙保护著它。从
这里没有路可以前往那城镇。
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/10,8.erosmia", 
		"east"	: "/d/erosmia/11,9.erosmia", 
		"west"	: "/d/erosmia/9,9.erosmia",
		]) );
	set( "original", "d/erosmia/10,9" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 9 );
	reset();
}
