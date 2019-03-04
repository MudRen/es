#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("laurel", "月桂叶");
	add ("id",({ "laurel"}));
	set_short("月桂叶");
	set_long(
		 "这是一束芬芳的月桂叶。人们常用它来表达坚贞的情感和对英雄的崇敬。\n"
		 "它的花语是：真情至死不渝、最崇拜的英雄。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

