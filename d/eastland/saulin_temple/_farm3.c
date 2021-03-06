// File: /d/eastland/saulin_temple/farm3.c
// Generated by Roommaker Wed Nov 22 23:13:13 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("菜园");
	ob->set_long( @LONG_DESCRIPTION
这里是一片宽阔的菜园，园中此刻正有许\多僧人和长工在工作著，
这些田地都是少林寺的庙产，所收成的五谷\蔬果除了能自给自足外还能
卖给批发商，当然，所有的庙产盈馀都是用於济助四乡贫民。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/farm4", 
		"south" : "/d/eastland/saulin_temple/farm1" ]) );
	ob->set( "objects", ([ 
		"worker" : "/d/eastland/saulin_temple/monster/worker" ]) );
	ob->reset();
}
