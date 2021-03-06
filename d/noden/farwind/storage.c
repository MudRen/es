//#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;

void create()
{
	::create();
	set_short("储物室");
	set_long( @C_LONG_DESCRIPTION
这里是一间老旧的储藏室，墙角、天花板到处布满蜘蛛网，地上一层厚
厚的灰尘。一些杂七杂八的东西到处散置，也许你可以发现一些有用的东西
。靠近墙边有一个橱柜(cupboard)，里面可能有一些有用的东西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([
		"cupboard" : "这个橱柜十分老旧，上面积满了灰尘，也许你必须找\n"
					"一找(search)，才能确定里面有没有东西。\n"
	]) );

	set( "exits", ([
		"down" : "/d/adventurer/hall/adv_guild"
	]) );
	set( "objects", ([
		"knife" : "/d/noden/farwind/items/knife"
	]) );
	reset();
}

void init()
{
	add_action( "do_search", "search" );
}

void reset()
{
	::reset();
	cup = 1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="cupboard" )
		return notify_fail( "你在仓库中找来找去，弄得满身灰尘。\n");
	if( cup ) {
		write( "你仔细搜索橱柜，结果只找到一个空纸杯。\n");
		obj = new("/d/noden/farwind/items/cup");
		obj->move(this_object());
		cup = 0;
		return 1;
	} else {
		write( "你把橱柜里里外外，上下左右都仔细看过一遍，只有灰尘和木屑。\n");
		return 1;
	}
}
