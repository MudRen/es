#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("turban", "缠头巾");
        add( "id", ({ "turban" }) );
        set_short( "缠头巾");
        set_long(
                "地精爱用的缠头布。\n"
        );
        set("unit","条");
        set( "type", "head" );
        set("material","cloth") ;
// set( "armor_class", 3 );
   set( "armor_class", 5 );
// set( "defense_bonus", 7 );
   set( "defense_bonus", 5 );
// fixed by mad
        set( "weight", 30 );
        set( "value", ({ 2, "gold" }) );
}



