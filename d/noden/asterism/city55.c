// File: /d/noden/asterism/city55.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("城市大路");
	set_long( 
		@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的大道路,由於半身人灵巧的设计天份及矮人的
建筑技巧,这里的道路十分宽敞笔直,而且道路两旁种植的树木花草在相互搭配之下,
让人好像置身於一座优美的公园。在东边有一座高塔(tower) ,上面有著一面象徵著
半身人的旗子.西边是很坚固的城墙,经过数百年的风吹日晒,依然屹立不摇。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set("c_item_desc",([
	    "tower":"一座建筑的很宏伟的高塔.\n"
	    ]) );
	set( "exits", ([ 
		"south" : ASTR"city56",
		"north" : ASTR"city54",
		]) );
	reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str||str!="tower") return 0;
    write("你进入了塔中.\n");
    this_player()->move_player(ASTR"tower1-1",
               "%s进入了塔中.\n","%s从外面进来.\n");
     return 1;
}
