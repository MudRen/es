#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy boots", "神圣之鞋");
        add( "id", ({ "boots" }) );
        set_short("a pair of holy boots", "神圣之鞋");
        set_long(
                "A pair of boots with holy power .\n",
                "一双有著神圣力量的鞋子\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "leather"); 
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense" , ([ "divine":8, "fire":-5 ]) ); 
        set( "weight", 100 );
        set( "value", ({ 1600, "silver" }) );
}
