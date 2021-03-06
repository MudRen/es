#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril leggings", "米苏里胫甲");
        add( "id", ({"leggings" }) );
        set_short("a pair of mithril and silver leggings", "银米苏里胫甲");
        set_long(
                "A pair of leggings made of mithril and silver.\n",
                "一双由米苏里金属与银造成的胫甲\n"
        );
        set( "unit", "双");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 150 );
        set( "value", ({ 950, "silver" }) );
}
