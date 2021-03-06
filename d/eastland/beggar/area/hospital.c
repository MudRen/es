#include "../dony.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("药铺");
	set_long( @C_LONG
你一走进这家药铺就闻到一股药草味。 这里是『薪胆村』唯一的一家可以医
疗的药铺 ,主人小雪子精通医术,而这里所卖的东西也不贵, 所有的东西则全写在
一张挂在壁上的画轴(paper)上。你可以看看它并且买你所需要的。
C_LONG
	);
	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"up":DBEGGAR"hospital1.c",
		"east":DBEGGAR"north1.c"
		       ]) );
	
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}
