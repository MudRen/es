#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith helmet", "矮灵头盔");
        add( "id", ({ "helmet" }) );
        set_short("矮灵头盔");
        set_long(
                "这件头盔乃是经过祭师科拉克以大地之能源炼制而成。\n"
        );
        set("unit","件");
        set( "type", "head" );
        set( "material", "element");
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "energy":5 ]) );
        set( "weight", 120 );
        set( "value", ({ 130, "gold" }) );
}






