#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("gloves of power", "力量手套");
        add( "id", ({"gloves" }) );
        set_short("a pair of gloves of power", "力量手套");
        set_long(
                "An gloves of power.\n",
                "一双强力手套,可以让你挥动武器更加有力\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "material", "heavy_metal" );
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "weight", 55 );
        set("extra_stats",([ "str":1 ]));
        set( "value", ({ 4000, "silver" }) );
}
