#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("tuberose", "夜来香");
        add ("id",({ "tuberose"}));
	set_short("夜来香");
	set_long(
		 "这是一束芬芳□丽的夜来香。\n"
		 "它的花语是：危险的快乐。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

