// File: /d/deathland/island/mountain01.c
// Generated by Roommaker Thu Nov 23 19:51:20 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("灰暗之岛的山岳");
	ob->set_long( @LONG_DESCRIPTION
这里是灰暗之岛地势较高的地方, 你觉得你每一步都相当浪费你的力气. 往东北
方看过去, 你只能看到一片光秃秃的山岳, 隐隐约约地一条小径蜿沿而上.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"southwest" : "/d/deathland/island/i01", 
		"northeast" : "/d/deathland/island/mountain02" ]) );
	ob->reset();
}
