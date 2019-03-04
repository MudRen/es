#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Dwarven shortsword","矮人短剑");
        add("id",({"shortsword","sword"}) );
       set_short("矮人短剑");
       set_long(
         "这是矮人所用的锋利短剑.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 14 );
       set("type","shortblade");
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 100 );
	set( "value", ({ 570, "silver" }) );
}
