#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("scholar's robe", "学者之袍");
        add( "id", ({ "robe" }) );
        set_short("学者之袍");
        set_long(
                "这件长袍是学者所穿著的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 11 );
        set( "weight", 150 );
        set( "value", ({ 30, "gold" }) );
}






