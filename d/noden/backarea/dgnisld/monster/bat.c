#include "../dgnisld.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(3);
	set_name( "Bats", "����" );
	add ("id", ({ "bat", "small_bat", "bats" }) );
	set_short( "a group of bats", "С����" );
	set_long(
           "A small bat.\n",
           "һֻС����\n"         
	);
	
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 3 );
	set_perm_stat( "con", 7 );
	set_perm_stat( "piety", 1);
	set_perm_stat( "karma", 5);
    set ("max_hp", 100);
    set ("hit_points",100);
    set ("natural_weapon_class1", 7);
    set ("natural_armor_class", 18);
    set ("natural_min_damage1", 5);
    set ("natural_max_damage1", 10);
    set ("weight", 50);
    set ("unit", "ֻ");
    set ("exp_reward",120);
    set_c_verbs( ({ "%sץ%s", "%sҧ%s", }) );
    set_c_limbs( ({ "ͷ", "���", "����" }) );
}
