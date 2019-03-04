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
        set("unit","øÈ");
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}