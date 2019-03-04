#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel shortsword", "精钢短剑" );
	add( "id", ({ "shortsword", "sword" }) );
	set_short( "a highsteel shortsword", "精钢短剑" );
	set_long(
		"You see an excellent shortsword made of highsteel.\n",
		"这是一把千锤百□，纯钢锻成的短剑，是本镇剑庐的精品。\n"
	);
	set( "unit", "把" );
	set( "weight", 90 );
	setup_weapon( "shortblade", 25, 11, 22 );
//	set( "bleeding", 5 );
	set( "value", ({ 420, "silver" }) );
}
