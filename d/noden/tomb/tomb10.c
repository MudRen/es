// File: /d/noden/tomb/tomb10.c
// Generated by Roommaker Tue Oct  4 10:22:15 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("墓室");
	set_long( @LONG_DESCRIPTION
这里是一条狭窄的通道，地上铺满了腐烂的叶子，一股动物粪便的味道
使你不由得捏住了鼻子，两边的墙壁长满了白色的苔藓，中间夹著几道不知
从哪里流下来的迳流，你注意到地上似乎有一些泥泞的脚印(footprints)，
通往南边的房间。
LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"footprints" : "这些脚印印在落叶上，形状已经十分模糊了，不知道是什麽生物留下的。\n" ]) );
	set( "exits", ([ 
		"north" : "/d/noden/tomb/tomb11", 
		"south" : "/d/noden/tomb/tomb9" ]) );
	reset();
}
