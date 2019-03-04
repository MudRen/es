#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron blade", "铁刀" );
	add( "id", ({ "blade" }) );
	set_short( "铁刀" );
	set_long(
		"这是一把用生铁铸成的刀子，看来有点粗制烂造的。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "value", ({ 220, "silver" }) );
}
