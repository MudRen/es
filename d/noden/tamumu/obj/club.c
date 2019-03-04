#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "club", "狼牙棒" );
	add( "id", ({ "spiked club" }) );
	set_short( "狼牙棒" );
	set_long(
   "这根狼牙棒上面有许多尖尖的铁刺，看起来是件沈重的战士级武器。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 7 );
	set( "max_damage", 24 );
	set( "weight", 170 );
	set( "value", ({ 230, "silver" }) );
}
