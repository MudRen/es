//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("微风路");
	set_long( @LONG_DESCRIPTION
你现在正走在微风路上。广场位於你的西方不远处，微风路向东
一路延伸下去，北边的建筑物是本镇唯一的书店，南边则是一栋奇怪
的建筑，似乎不断地散发著强烈的魔法。
LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
        "north" : "/d/noden/farwind/bookshop",
		"east" : "/d/noden/farwind/bazz3",
		"west" : "/d/noden/farwind/bazz1",
	        "south" : "/d/noden/farwind/auc_room",
	]) );
    create_door("north","south",
    	 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木门",
		     "c_desc"  : "这是一扇可爱的小木门，门上挂了一个书店的招牌",		
		     "status"  : "open",
		]) );
    reset();
}
