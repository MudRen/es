// File: /d/eastland/forest/6,0.forest.c
// Generated by Roommaker Fri Nov 24 12:48:59 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("森林的内部");
	ob->set_long( @LONG_DESCRIPTION
你现在正身处於猛兽森林的内部，狂暴的气息令人不寒而栗，尤其是
此起彼落的野兽狂啸声，更是让人胆颤心惊。要是没有什麽重要的事，还
是快快回头的好。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"northwest" : "/d/eastland/forest/5,1.forest", 
		"northeast" : "/d/eastland/forest/7,1.forest" ]) );
	ob->set( "objects", ([ 
		"antelope#0" : "/d/eastland/forest/monster/antelope", 
		"antelope#1" : "/d/eastland/forest/monster/antelope" ]) );
	ob->reset();
}
