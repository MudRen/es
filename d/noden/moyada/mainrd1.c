//#pragma save_binary

// translation done -Elon 03-10-94
#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
   set_short( "主要道路" );
	set_long( @LONG_DESCRIPTION
你现在站在摩亚达城的主要道路，它大多以破碎的砖石所铺制而成
。往南是城中心的圆形广场与「银色之塔」，向北则是北门。东边有一
栋新盖的木造房子。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
	    "east"  : MOYADA"shop/wanfu_shop.c",
		"south" : MOYADA"mainrd5.c", 
		"north" : MOYADA"n_gate.c",  ]) );

    create_door( "east", "west", ([
        "keyword" : ({ "wooden door", "door", }),
        "name"    : "wooden door",
        "c_name"  : "木门",
        "c_desc"  : "全新的木门",
        "status"  : "open",
    ]) );
	reset();
}
