#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy boots", "��ʥ֮Ь");
        add( "id", ({ "boots" }) );
        set_short("a pair of holy boots", "��ʥ֮Ь");
        set_long(
                "A pair of boots with holy power .\n",
                "һ˫������ʥ������Ь��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather"); 
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense" , ([ "divine":8, "fire":-5 ]) ); 
        set( "weight", 100 );
        set( "value", ({ 1600, "silver" }) );
}
