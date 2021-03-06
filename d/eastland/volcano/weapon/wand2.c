#include "../oldcat.h"

inherit WEAPON;

void create()
{
	set_name("elder's wand", "长老法杖");
	add ("id",({ "wand",}) );
	set_short("长老法杖");
	set_long(
        "这是一把能将持杖者的魔法力作最有效应用的魔杖。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 41 );
	set( "type", "wand" );
        set( "min_damage", 19 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "value", ({ 5000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "energy" );
	set( "special_damage", 80 );
	set( "special_c_msg","利用施法者的魔法能源，产生一股强大的能量，无数的能量射线\n贯穿所有的敌人。\n" );
}
