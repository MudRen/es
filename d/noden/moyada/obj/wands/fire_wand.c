#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire wand", "火杖" );
	add( "id", ({ "wand" }) );
	set_short( "火杖" );
	set_long(@CLONG
这是一把火杖，如果你对这类型的魔法武器有研究的话，这种武器
将会是不错的选择。
CLONG
        	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 10 );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "power_on", 1);
	set( "weight", 40 );
	set( "value", ({ 500, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 15 );
	set( "special_c_msg", "从杖头射出一颗火球！" );
}
