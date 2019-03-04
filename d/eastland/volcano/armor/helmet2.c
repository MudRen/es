#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("gold crown", "紫金冠");
        add( "id", ({ "crown" }) );
        set_short("紫金冠");
        set_long(
                "这个冠冕能使人戴上之後有莫大的荣耀。\n"
        );
        set("unit","件");
        set( "type", "head" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "energy":5 ]) );
        set( "weight", 120 );
        set( "value", ({ 230, "gold" }) );
        set( "no_sell",1);
}






