#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flamming wand", "火焰杖" );
	add( "id", ({ "wand" }) );
	set_short( "火焰杖" );
	set_long(
		"这是一把火焰杖，如果你对这类型的魔法武器有研究的话，这种武器\n"
		"将会是不错的选择。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 13 );
	set( "min_damage", 4 );
	set( "max_damage", 10 );
	set( "weight", 50 );
	set( "value", ({ 680, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 5 );
	set( "max_charge", 5 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 30 );
	set( "special_c_msg", "从杖头冒出熊熊的火焰！" );
}

