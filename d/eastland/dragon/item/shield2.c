#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("jade shield", "ôä´ä¶ÜÅÆ");
        add( "id", ({ "shield" }) );
        set_short("ôä´ä¶ÜÅÆ");
        set_long(
                "ÕâÊÇÒ»ÃæÏâÂúôä´äµÄ¶ÜÅÆ\n"
        );
        set("unit","¿é");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([ "electric":3 ]) );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}