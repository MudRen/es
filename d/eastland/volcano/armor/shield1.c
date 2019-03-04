#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith shield", "矮灵盾");
        add( "id", ({ "shield" }) );
        set_short( "矮灵盾");
        set_long(
                "这只盾乃是经过祭师科拉克以魔法力量炼制而成。\n"
        );
        set("unit","只");
        set( "type", "shield" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "magic":5 ]) );
        set( "no_sale",1);
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
