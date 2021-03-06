// File: /d/eastland/saulin_temple/unsu_temple.c
// Generated by Roommaker Wed Nov 22 23:24:50 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("文殊院");
	ob->set_long( @LONG_DESCRIPTION
这里是供奉文殊菩萨的地方，正堂上供奉著骑青狮的文殊菩萨，温和微笑
的文殊菩萨是大智慧的象徵，所以现在正有许\多在佛理上产生疑问的僧人对著
菩萨沈思，祈求菩萨能赐给他们破除迷惘的智慧。门外是一片宁静的树林。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/forest3", 
		"south" : "/d/eastland/saulin_temple/unsu_room2", 
		"north" : "/d/eastland/saulin_temple/unsu_room1" ]) );
	ob->set( "objects", ([ 
		"monk2" : "/d/eastland/saulin_temple/monster/kon_hwei", 
		"monk" : "/d/eastland/saulin_temple/monster/hwa_wan" ]) );
	ob->reset();
}
