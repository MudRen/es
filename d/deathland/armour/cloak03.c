#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("beautiful cloak", "Æ¯ÁÁµÄ¶·Åî");
        add( "id", ({ "cloak" }) );
        set_short("a beautiful cloak", "Æ¯ÁÁµÄ¶·Åî");
        set_long(
                "A beautiful cloak.\n",
                "Ò»¼şÆ¯ÁÁµÄ¶·Åî.\n" 
        );
        set("unit","¼ş");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([ "mental":3, "fire":-5 ]) );
        set( "weight", 75 );
        
        set( "value", ({ 1800, "silver" }) );
}
