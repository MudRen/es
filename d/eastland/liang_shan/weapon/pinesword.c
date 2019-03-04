#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("pine sword","松文古定剑");
       add("id",({"sword","pinesword",}) );
       set_short("松文古定剑");
	   set_long(
           "一把上面有著松树花纹的古代木剑，年代似乎相当久远．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set("type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 35 );
	set( "weight", 80 );
	set( "value", ({ 510, "gold" }) );
}
