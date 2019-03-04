#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult shield", "…Ò√ÿ∂‹≈∆");
        add( "id", ({ "shield" }) );
        set_short("…Ò√ÿ∂‹≈∆");
        set_long(
                "…Ò√ÿ∂‹≈∆\n"
        );
        set("unit","√Ê");
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}