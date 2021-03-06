#include <mudlib.h>

inherit MONSTER;

void create ()
{
	::create();
	set_level(6);
	set_name( "Bats King", "大蝙蝠" );
	add ("id", ({ "bat", "king",}) );
	set_short( "大蝙蝠" );
	set_long(
           "一只大蝙蝠，就像一只蝙蝠王。它有巨大的身体和尖锐的牙齿。\n"
	);
	
	set_perm_stat( "dex", 8 );
	set_perm_stat( "str", 7 );
	set_perm_stat( "int", 4 );
	set_perm_stat( "con", 9 );
	set_perm_stat( "piety", 1);
	set_perm_stat( "karma", 6);
    set ("max_hp", 200);
    set ("hit_points", 200);
    set ("natural_weapon_class1", 14);
    set ("natural_armor_class", 35);
    set ("natural_min_damage1", 8);
    set ("natural_max_damage1", 15);
    set ("weight", 100);
    set ("exp_reward",300);
    set ("unit", "只");
    set_c_verbs( ({ "%s抓%s", "%s咬%s" }) );
    set_c_limbs( ({ "头", "翅膀", "身体" }) );
}
