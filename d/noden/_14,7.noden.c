// File: /d/noden/14,7.noden.c
// Generated by Roommaker Mon Nov 20 12:36:15 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石板桥");
	ob->set_long( @LONG_DESCRIPTION
你现在正站在一座石板桥的桥面上，桥下河水正缓缓地由西向东流去，你
可以看见北方不远处远风镇的街道和商店。过桥往南是一条碎石铺成的道路，
通往衔接诺顿王国东西的主要道路。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"west" : "d/noden/13,7.noden", 
		"north" : "/d/noden/farwind/smain2", 
		"south" : "d/noden/14,8.noden" ]) );
	ob->set( "no_monster", 1 );
	ob->set( "objects", ([ 
		"orc rogue" : "/d/noden/monster/orc", 
		"halfling girl" : "/d/noden/monster/halfling" ]) );
	ob->set( "original", "d/noden/14,7" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "weight", 0 );
	ob->set( "x_coordinate", 14 );
	ob->set( "y_coordinate", 7 );
	ob->reset();
}
