#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven armband", "精灵臂环");
        add( "id", ({ "armband" }) );
        set_short( "精灵臂环" );
        set_long(
                "这是精灵长老用独角兽的独角所磨制成的臂环，其上有种奇特的保护光芒。 \n"
        );
        set( "unit", "双");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":7, "evil":-3, "fire":-1, "poison":-2 ]) );
        set( "weight", 30 );
        set( "value", ({ 1800, "silver" }) );
}
