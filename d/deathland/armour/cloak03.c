#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("beautiful cloak", "Ư���Ķ���");
        add( "id", ({ "cloak" }) );
        set_short("a beautiful cloak", "Ư���Ķ���");
        set_long(
                "A beautiful cloak.\n",
                "һ��Ư���Ķ���.\n" 
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([ "mental":3, "fire":-5 ]) );
        set( "weight", 75 );
        
        set( "value", ({ 1800, "silver" }) );
}
