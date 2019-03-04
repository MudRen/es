#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("green shining ring", "绿色闪亮戒指");
        add( "id", ({ "ring" }) );
        set_short( "绿色闪亮戒指");
        set_long(
                " 一个闪闪发光的绿色戒指\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "weight", 15 );
        set( "value", ({ 77, "gold" }) );
}



