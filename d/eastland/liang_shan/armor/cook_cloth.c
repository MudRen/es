#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("cook cloth","油腻的厨师服");
    add("id",({"cloth"}) );
    set_short( "cook cloth","油腻的厨师服");
	set_long(
		"???\n",
		"这是一件看来很油腻的厨师工作服,散发出一股难闻之气味\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 140, "gold" }) );
}
