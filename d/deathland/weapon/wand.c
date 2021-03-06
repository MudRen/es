#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("fire wand", "地火之杖");
	add ("id",({ "wand",}) );
	set_short("地火之杖");
	set_long(
        "这是一把能呼唤「火球」的魔杖，你隐约可以看见杖头闪著几丝火光。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
	set( "type", "wand" );
	set( "min_damage", 10 );
	set( "max_damage", 18 );
	set( "weight", 60 );
	set( "value", ({ 200, "gold" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 15 );
	set( "max_charge", 15 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 15 );
//	set( "special_msg", " launches a fireball, you are almost stunned!\n" );
	set( "special_c_msg", "发出一团火球,击向你的身体而燃烧\n" );
}
