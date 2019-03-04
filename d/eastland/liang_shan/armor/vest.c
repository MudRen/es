#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("cell vest","格子布背心");
    add("id",({"cell","vest"}) );
    set_short( "cell vest","格子布背心");
	set_long(
		"This is a suit of vest \n",
		"这是一件格子花纹的小背心．\n"
		
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "armor_class", 20 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 90, "gold" }) );
}
