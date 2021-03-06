#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("ivory dagger", "象牙匕首");
	add( "id", ({ "dagger" }) );
	set_short("象牙匕首");
	set_long(
		"一把精巧的象牙柄匕首，上面镶著许多宝石。\n"
	);
	set( "unit", "把" );
	set( "weight", 50 );
	set( "type", "dagger" );
	set( "weapon_class", 30 );
	set( "min_damage", 10 );
	set( "max_damage", 22 );
	set( "second", 1 );
	set( "value", ({ 165, "gold" }) );
}
