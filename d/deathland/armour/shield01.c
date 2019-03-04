#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name( "warlord shield", "战神盾牌");
        add( "id", ({ "shield" }) );
        set_short("a warlord shield", "战神盾牌");
        set_long(
                "mithril shield of protection .\n",
           "这是用米苏里金属与银混合所制成的盾，由历代的矮人将军一直传下来 \n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus",3 );
        set( "weight", 100 );
        set( "value", ({ 350, "gold" }) );
}






