#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("green chainmail","点翠团花战甲");
    add("id",({"chainmail","mail"}) );
    set_short( "green chainmail","点翠团花战甲");
	set_long(
		"This is a suit of green chainmail \n",
		"这是一件绿油油的□甲，不知道是用什麽金属制成的，胸前有\n"
		"许\多美丽的绣花图案．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 290, "gold" }) );
}
