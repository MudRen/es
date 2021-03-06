#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "icewind wand", "冰岚杖" );
	add( "id", ({ "wand" }) );
	set_short( "冰岚杖" );
	set_long(
		"这是一把蓝色的魔杖，上面还有许多霜状的凝结物附著在杖头。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 30 );
	set( "min_damage", 8 );
	set( "max_damage", 14 );
	set( "weight", 50 );
	set( "value", ({ 980, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 50 );
	set( "special_c_msg", "从杖头发出一股冷洌的寒风，你看到周围的空气被带出一团冰雾！" );
}

