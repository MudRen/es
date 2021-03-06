#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long cutlass", "长弯刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "长弯刀" );
	set_long(
		"一把长而精致的弯刀，它看起来十分锐利。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 17 );
	set( "weight", 70 );
	set( "value", ({ 320, "silver" }) );
}
