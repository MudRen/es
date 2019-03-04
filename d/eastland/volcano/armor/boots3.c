#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("cloud boots", "步云靴");
        add( "id", ({ "boots" }) );
        set_short( "步云靴");
        set_long(
                "这双靴子乃是神仙们常穿的鞋，据说可以踏云而行。\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 280, "gold" }) );
}






