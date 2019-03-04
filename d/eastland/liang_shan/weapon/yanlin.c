#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("yanling blade","雁翎刀");
       add("id",({"blade"}) );
       set_short("雁翎刀");
	   set_long(
           "这是绿林好汉最喜爱的刀子，因为它非常好使，威力也不错．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
        set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 33 );
	set( "weight", 70 );
	set("bleeding",5);
	set( "value", ({ 90, "gold" }) );
	
}	
