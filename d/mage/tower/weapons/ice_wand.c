#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("ice wand", "寒冰杖");
	add ("id",({ "wand",}) );
	set_short("a ice wand","寒冰杖");
	set_long(
	    "A magical wand which can cast sleet.\n",
        "用玄天寒冰制成，据说能引起「冰雹」的魔杖。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 45 );
	set( "type", "wand" );
        set( "min_damage", 20 );
        set( "max_damage", 40 );
	set( "weight", 50 );
	set( "no_sale", 1 );
	set( "value", ({ 8000, "silver" }) );
	// set this weapon as magical weapon.
	set( "hit_func", "wand_hit" );
    set( "power_on", 1);
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 75 );
	set( "special_msg", " causes sleet." );
	set( "special_c_msg", "引发「冰雹」，风雪无情的肆虐！" );
}
