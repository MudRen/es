
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red steel plate","红铠甲");
        add("id",({"plate","platemail"}) );
         set_short( "a red steel plate","红铠甲");
        set_long(
"This is a suit of plate make by red steel ,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副由红色魔法磁铁矿打造而成的铠甲，通体泛著奇特的光芒。\n"
        );
        set( "unit", "副" );
        set( "weight", 400 );
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 3 );
	set( "material", "heavy_metal" );
        set( "value", ({ 680, "gold" }) );
}
