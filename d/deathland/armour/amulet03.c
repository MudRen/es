#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("life amulet","长命符");
        add("id",({"amulet"}) );
         set_short( "a life amulet","长命符");
	set_long(
"通常矮人小孩一出生,就会被带上这个长命符,以期望小孩子能长命百岁,健健康康\n"
	);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "armor_class", 0 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "evil":2 ]) );
	set( "value", ({ 5, "gold" }) );
}
