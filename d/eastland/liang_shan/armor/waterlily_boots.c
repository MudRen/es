#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("waterlily boots", "藕丝步云履");
        add( "id", ({ "boots" }) );
        set_short("藕丝步云履");
        set_long(
                "这是由莲藕的纤维所制成的鞋子，质轻而且十分耐用．\n"
        );
        set( "no_sale",1);
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "evil":8, "divine":-8,"poison":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 2740, "silver" }) );
}
