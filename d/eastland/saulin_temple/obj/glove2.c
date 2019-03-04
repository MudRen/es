#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("liu-li bracers", "琉璃手镯");
        add( "id", ({"bracers","bracer" }) );
        set_short("琉璃手镯");
        set_long(@C_LONG
一双由七彩琉璃石做成的手镯, 可以在战斗中散发出耀眼炫目的光芒
相传这是王母娘娘座下女神穿带的手镯。
C_LONG
       	);
        set( "unit", "对");
        set( "type", "hands" );
        set( "armor_class", 5 );
        set("material","stone");
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 1800, "silver" }) );
}
