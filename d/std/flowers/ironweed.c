#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("ironweed", "紫苑草");
        add ("id",({ "ironweed"}));
	set_short("紫苑草");
	set_long(
		 "这是一束美丽的紫苑草，人们常常用它来表达对往事的回忆。\n"
		 "它的花语是：回忆点点滴滴。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

