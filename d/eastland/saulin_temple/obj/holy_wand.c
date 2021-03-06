#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "holyword wand", "圣言杖" );
	add( "id", ({ "wand" }) );
	set_short( "圣言杖" );
	set_long(
		"这是一把黝黑的法杖，上面还刻绘有许\多奇特的符号。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 35 );
	set( "min_damage", 8 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "divine" );
	set( "special_damage", 40 );
	set( "special_c_msg", "从杖头发出一道金色的光芒 !!\n"+
	    "你看到各种真言、佛号在空中飞舞 !!\n" );
}

