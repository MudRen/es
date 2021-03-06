#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("道路");
	set_long( @LONG_DESCRIPTION
你现在正走在一条碎石铺成的道路上，沿著道路往北你可以看到诺达尼亚
的市街，诺达尼亚城位於米格兰山的山脚下，几百年来一直是诺顿王国的首都
与第一大城，也许你该进去看一看。路边竖著一块新漆好的牌子，上面写著「
天马号飞船载客站」。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
		"west" : "d/noden/5,8.noden", 
		"north" : "/d/noden/nodania/nodania_r1", 
		"south" : "d/noden/6,9.noden", 
		"east" : "d/noden/7,8.noden" ]) );
	set( "no_monster", 1 );
	set( "original", "d/noden/6,8" );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 8 );
	reset();
	replace_program(ROOM);
}

void init()
{
	if( !find_object("/d/std/cloud/airship_pegasus") )
		"/d/std/cloud/airship_pegasus"->frog();
}
