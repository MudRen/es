#include "../dgnisld.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(6);
	set_name( "Bats King", "������" );
	add ("id", ({ "bat", "bats", "bats_king", "king", "bats king" }) );
	set_short( "a large bat", "������" );
	set_long(
           "A large bat, just like the king of bats. It has acuminate teeth,\n"
        "and larger body then normal bat.\n",
           "һֻ�����𣬾���һֻ�����������о޴������ͼ�������ݡ�\n"
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
    set ("unit", "ֻ");
    set_c_verbs( ({ "%sץ%s", "%sҧ%s" }) );
    set_c_limbs( ({ "ͷ", "���", "����" }) );
}
