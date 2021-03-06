#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("dagger", "匕首");
	set_short("a short dagger", "短匕首");
	set_long(
		"A fairly short dagger with sharp thin blade.\n",
		"一把小巧精致的匕首。\n"
	);
	set( "weapon_class", 7 );
	set( "type", "dagger" );
	set( "min_damage", 4 );
	set( "max_damage", 6 );
	set( "weight", 15 );
	set( "value", ({ 5, "gold" }) );
}
