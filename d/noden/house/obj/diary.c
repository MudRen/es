#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "old diary", "破旧日记" );
	add( "id", ({ "diary" }) );
   set_short( "破旧日记" );
	set_long(
		"这本日记看起来有几百年的岁月了，你可以读读看(read)。\n"
	);
	set( "unit", "本" );
	set( "weight", 5 );
	set( "useless" );
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->more("/d/noden/house/diary", 0, 1);
	return 1;
}
