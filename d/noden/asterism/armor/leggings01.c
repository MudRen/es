#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("brass leggings", "»ÆÍ­ëÖ¼×");
        add( "id", ({ "leggings" }) );
        set_short("»ÆÍ­ëÖ¼×");
        set_long(
                "ÕâÊÇÒ»Ë«»ÆÍ­ëÖ¼×.\n"
        );
        set("unit","Ë«");
        set( "type", "legs" );
        set("material","light_metal") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "weight", 110 );
        set( "value", ({ 70, "gold" }) );
}






