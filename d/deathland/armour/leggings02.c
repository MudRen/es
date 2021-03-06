#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black mithril leggings", "黑色米苏理护膝");
        add( "id", ({"leggings" }) );
        set_short("a pair of black mithril leggings", "黑色米苏理护膝");
        set_long(
                "A pair of leggings made of mithril and some mystic metal.\n",
                "一双由米苏里与某种神秘的金属造成的胫护膝\n"
        );
       // set("no_sale",1);
        set( "unit", "双");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 100 );
        set( "value", ({ 5700, "silver" }) );
}
