//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("微风路");
	set_long( @C_LONG_DESCRIPTION
你现在正走在微风路上。广场位於你的西方不远处，微风路向东
一路延伸下去，北边的建筑物是本镇唯一的酒吧。
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"north" : "/d/noden/farwind/wineshop",
		"east" : "/d/noden/farwind/bazz2",
		"west" : "/d/noden/farwind/square",
		"south" : "/d/noden/farwind/hocker.c"
	]) );
    create_door("north","south",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木门",
		     "c_desc"  : "这是一扇可爱的小木门，门上挂了一个酒店的招牌。\n",		
		     "status"  : "open"
		]) );
   reset();

}
