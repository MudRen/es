#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("holy dagger","神圣匕首");
       add("id",({"dagger",}) );
       set_short("a holy dagger","神圣匕首");
       set_long(
           "A dagger enchanted holy power.\n",
           "一把附有神圣力量匕首.\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    set("type","dagger");
	set( "min_damage", 22 );
	set( "max_damage", 30 );
	set( "weight", 80 );
	set( "value", ({ 3000 , "silver" }) );

}
