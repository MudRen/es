#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("wooden oar","木桨");
       add("id",({"oar",}) );
       set_short("wooden oar","木桨");
       set_long(
           "A oar made by oak.\n",
           "这是一把用上好桧木削制而成的船桨。\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
	set("type","blunt");
	set( "min_damage", 10 );
	set( "max_damage", 25 );
	set( "weight", 200 );
	set( "value", ({ 20, "gold" }) );
}
