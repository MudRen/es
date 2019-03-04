#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith ring", "矮灵戒指");
        add( "id", ({ "ring" }) );
        set_short( "矮灵戒指");
        set_long(
                "这只戒指乃是经过祭师科拉克以剧毒力量炼制而成。\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "poison":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 120, "gold" }) );
}






