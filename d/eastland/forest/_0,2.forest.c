// File: /d/eastland/forest/0,2.forest.c
// Generated by Roommaker Fri Nov 24 00:01:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("森林的边缘");
	ob->set_long( @LONG_DESCRIPTION
你现在所在的地方是一片茂密的森林，似乎就是人们所说的猛兽森林
。传说猛兽森林中有很多凶猛的野兽，有不少的人在此失踪，如果没有什
麽必要，千万不要随便进入森林内部。                
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/forest/2,2.forest", 
		"west" : "/d/eastland/4,17.east", 
		"southeast" : "/d/eastland/forest/1,1.forest", 
		"northeast" : "/d/eastland/forest/1,3.forest" ]) );
	ob->set( "objects", ([ 
		"squirrel#0" : "/d/eastland/forest/monster/squirrel", 
		"squirrel#2" : "/d/eastland/forest/monster/squirrel", 
		"squirrel#1" : "/d/eastland/forest/monster/squirrel" ]) );
	ob->reset();
}
