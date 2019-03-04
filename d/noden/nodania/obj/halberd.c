#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("halberd", "长戟");
	set_short("钢制长戟");
	set_long(
		"这种长戟通常是诺顿皇家骑士团的骑士所喜爱的武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 160 );
	set( "type", "polearm" );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "value", ({ 1900, "silver" }) );
}
