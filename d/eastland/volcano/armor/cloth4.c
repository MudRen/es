#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("wraith elder's robe", "矮灵长老之袍");
        add( "id", ({ "robe" }) );
        set_short( "矮灵长老之袍");
        set_long(
                "这件长袍是矮灵长老穿著的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 20 );
        set( "defense_bonus", 8);
        set( "weight", 160 );
        set( "value", ({ 40, "gold" }) );
}






