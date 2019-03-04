#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Famous Sword", "名剑" );
    add("id", ({"sword","famous sword"}) );
    set_short("名剑「长歌」");
	set_long(
           "一把非常有名的长剑，在剑锷处铸了两个小字  --- 「长歌」\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 33 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 35 );
	set( "weight", 90 );
	set( "value", ({ 240, "gold" }) );
}

