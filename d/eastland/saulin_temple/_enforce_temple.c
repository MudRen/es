// File: /d/eastland/saulin_temple/enforce_temple.c
// Generated by Roommaker Wed Nov 22 23:26:39 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("戒律院");
	ob->set_long( @LONG_DESCRIPTION
你走进一个大厅堂，厅堂两侧各排了一排戒棍，堂上供奉著一尊大
佛，旁边还有两尊怒目金刚，炯炯双目好像警惕著长跪在堂前忏悔的几
名僧人。四周还有几名轮值的掌刑弟子，正专心的督导犯错的僧人念经
。门外是一片宁静的树林，。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/enforce_room1", 
		"south" : "/d/eastland/saulin_temple/enforce_room2", 
		"west" : "/d/eastland/saulin_temple/forest5" ]) );
	ob->set( "objects", ([ 
		"enforcer" : "/d/eastland/saulin_temple/monster/enforcer", 
		"enforcermaster" : "/d/eastland/saulin_temple/monster/gun" ]) );
	ob->reset();
}
