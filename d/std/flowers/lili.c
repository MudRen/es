#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("lily", "白百合");
	add("id",({"lily"}) );
	set_short("白百合");
	set_long(
		 "这是一支清新高雅的白百合，人们常常用它来象徵纯美的少女。\n"
		 "它的花语是：纯洁无邪。\n"
		 "这支花上还系著一张小卡片。\n");
	set("unit", "支");
        set ("value", ({ 10, "silver" }) );
}
