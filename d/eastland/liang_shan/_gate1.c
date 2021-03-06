// File: /d/eastland/liang_shan/gate1.c
// Generated by Roommaker Tue Nov 21 15:57:02 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("梁山泊大寨门");
	ob->set_long( @LONG_DESCRIPTION
这就是闻名的梁山泊，经过数百年不断的整修扩建，已由原先的规模，
发展成一个极其壮观的山寨；它目前的规模，简直已和一个小小的城市差
不多了．从门外看来，那以巨大的树干编成的木栅，漆黑的大寨门，在风
中猎猎飘扬的五色旗帜，如果你没有相当的实力和勇气，最好还是别和他
们为敌．
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"eastup" : "/d/eastland/liang_shan/wall1", 
		"north" : "/d/eastland/liang_shan/path1", 
		"south" : "/d/eastland/liang_shan/out1", 
		"westup" : "/d/eastland/liang_shan/wall6" ]) );
	ob->set( "no_monster", 1 );
	ob->set( "objects", ([ 
		"bandit2" : "/d/eastland/liang_shan/monster/small_bandit", 
		"bandit1" : "/d/eastland/liang_shan/monster/small_bandit", 
		"huan" : "/d/eastland/liang_shan/monster/huan" ]) );
	ob->reset();
}
