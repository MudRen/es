#include "../island.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("老桐阁药铺分号");
	set_long( @C_LONG_DESCRIPTION
你一走进这家药铺，就闻到一股浓郁的檀香，这是由若岚城历史最老
的老桐阁药铺在此所开的分号。从寻常的刀伤药膏，到难得一见的千年老
参，这里都有，这家药铺还有一种祖传的刀伤药配方叫做「天香断续膏」
，治外伤灵验无比，这里所卖的药材与价钱都写在一张挂在壁上的卷轴
(paper)上。
C_LONG_DESCRIPTION
	);

	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"east" : ITOWN"town06" ]) );
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/eastland/easta/obj/plaster", 40, 40 }),
		({ "/d/eastland/easta/obj/white_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 20, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
		({ IOBJ"paste",20,20 }),
	}) );
	reset();
}
void reset()
{
      seller::reset();
      room::reset();
      return;
}
