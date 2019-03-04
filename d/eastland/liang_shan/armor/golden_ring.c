#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("golden ring","太原府纽丝金环");
        add("id",({"ring"}) );
         set_short( "golden ring","太原府纽丝金环");
	set_long(
"This is a golden ring . \n"
"这是太原府的特产，东方大陆的游客到太原府一定会买一个来戴戴\n"
);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","adventurer");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 150, "gold" }) );
        set( "extra_skills",(["whip":10]));
}
