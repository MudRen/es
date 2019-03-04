#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith amulet", "矮灵护身符");
        add( "id", ({ "amulet" }) );
        set_short("矮灵护身符");
        set_long(
                "这个护身符乃是经过祭师科拉克以强酸力量炼制而成。\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "acid":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 90, "gold" }) );
}






