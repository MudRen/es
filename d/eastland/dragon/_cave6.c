// File: /d/eastland/dragon/cave6.c
// Generated by Roommaker Sat Nov 25 14:00:30 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("龙穴");
	ob->set_long( @LONG_DESCRIPTION
当你进入此洞穴时你发现此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且
有时有一些奇怪的岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的
火红构成一副优美的景色，令你几乎忘了身在何处。
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/dragon/cave20", 
		"west" : "/d/eastland/dragon/cave21" ]) );
	ob->set( "objects", ([ 
		"fighter2" : "/d/eastland/dragon/monster/fighter", 
		"fighter1" : "/d/eastland/dragon/monster/fighter", 
		"fighter3" : "/d/eastland/dragon/monster/fighter" ]) );
	ob->reset();
}
