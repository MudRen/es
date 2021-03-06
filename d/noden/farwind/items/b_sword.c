#include "../farwind.h"

inherit WEAPON;

void create()
{
	set_name("heavy broadsword", "阔剑");
	add( "id", ({ "sword", "broadsword" }) );
	set_short("重型阔剑");
	set_long(
		"一把又长、又重而且锋利的阔剑，属於远风镇的保安官所有。\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 25 );
	set( "type", "longblade" );
	set( "min_damage", 13 );
	set( "max_damage", 28 );
	set( "bleeding", 10 );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "value", ({ 66, "gold" }) );
}
