#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("Chinese halbert","方天画戟");
       add("id",({"halbert"}) );
       set_short("方天画戟");
	   set_long(
           "戟是组合枪和长刀而成的武器，兼有两者的优点，方天画戟是其中\n"
	   "较有威力的一种．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
    set("type","polearm");
	set( "min_damage", 16 );
	set( "max_damage", 30 );
	set( "nosecond",1);
	set( "weight", 130 );
	set( "value", ({ 90, "gold" }) );
	
}	
