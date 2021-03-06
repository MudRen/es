#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "steel seal", "精钢封印" );
	add( "id", ({ "key","seal" }) );
	set_short( "a steel seal", "精钢封印" );
	set_long(
		"A magic seal made by high steel.\n",
		"这是一个铸成火焰形的纯钢封印，好像可以□入某个门里。\n"
	);
	set( "unit", "块" );
	set( "to_lock", "FIRE_ELEMENT_KEY" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
