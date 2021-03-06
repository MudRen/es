// File: /d/noden/asterism/tower1-1.c
// Generated by Roommaker Thu Nov 23 19:14:33 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("半身人高塔的底层");
	ob->set_long( @LONG_DESCRIPTION
这里是艾斯特律恩城中半身人高塔的底层,一些名贵的壁画以及昂贵的雕刻品让这地
方显得很气派,除此之外这里的守卫也十分森严,因为半身人族长就住在塔的最高层.
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"down" : "/d/noden/asterism/tower1-0", 
		"out" : "/d/noden/asterism/city55", 
		"up" : "/d/noden/asterism/tower1-2" ]) );
	ob->set( "objects", ([ 
		"guard#3" : "/d/noden/asterism/monster/halfling_guard01", 
		"guard#2" : "/d/noden/asterism/monster/halfling_guard01", 
		"guard#1" : "/d/noden/asterism/monster/halfling_guard01" ]) );
	ob->reset();
}
