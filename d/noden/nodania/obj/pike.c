#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("pike", "长枪");
	set_short("长枪");
	set_long(
		"这是一种在长柄木杖末端装上枪头的轻便武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 60 );
	set( "type", "polearm" );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 16 );
	set( "nosecond", 1 );
	set( "value", ({ 500, "silver" }) );
}
