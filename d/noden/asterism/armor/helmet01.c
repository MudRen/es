#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling helmet", "半身人头盔");
        add( "id", ({ "helmet" }) );
        set_short( "半身人头盔");
        set_long(
                "这是半身人守卫专用的头盔 \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set("material","light_metal") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 70 );
        set( "value", ({ 135, "gold" }) );
}



