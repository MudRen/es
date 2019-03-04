#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze staff", "青铜禅杖" );
	add( "id", ({ "staff" }) );
	set_short( "青铜禅杖" );
	set_long( "这是一把用青铜铸成的禅杖，看起来相当沈重。\n");
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 140 );
	set( "value", ({ 240, "silver" }) );
}
