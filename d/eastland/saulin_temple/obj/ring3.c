#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("tiger ring","伏虎指套");
    add("id",({"ring"}) );
    set_short("伏虎指套");
	set_long(
		"这是伏虎罗汉所使用的指套,可以提供你不错的防护力\n"
	);
	set( "unit", "个" );
	set( "weight", 19 );
        set("material","leather");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 2000, "silver" }) );
}
