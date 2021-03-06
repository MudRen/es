#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下甬道");
	set_long( 
@C_LONG_DESCRIPTION
这儿是一个长长的甬道，你可以看到前方隐约传来的亮光。一阵阵的风从前方吹来，
你想大概快到了吧.......
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/room5", 
		"south" : TOMB"/room1",  ]) );
	set( "objects", ([
		"guard1" : MOB"/guard1", 
		"guard2" : MOB"/guard1"]) );
	set( "pre_exit_func", ([
		"north" : "check_guard" ]) );
	reset();	
}

int check_guard()
{
   object guard;

   guard = present("guard", this_object());
   if( present("guard", this_object()) && guard->query("right_guard") )  {
		write("守卫说道: 国师有令，任何人不得进入。\n");
		return 1; }
	return 0;
}
