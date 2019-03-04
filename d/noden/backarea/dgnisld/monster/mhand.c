#include "../dgnisld.h"

inherit MONSTER;

void create ()
{
	int    exp;

	::create();
	set_level(10);
	set_name( "Hand", "����" );
	add ("id", ({ "hand", "mire","mire hand" }) );
	set_short( "a mired hand", "����" );
	set_long(
           "A mired hand, the dusty mire will make it strong. It lies on\n"
        "the swamp, its favorite home.\n",
           "һֻ���֣����������ϡ�������������ϲ�����ǻ���������������\n"
        "С����һ��ץס������Ͳ����ٷ��֡�\n"
	);
	
	set_perm_stat( "dex", 5 );
	set_perm_stat( "str",10 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 2);
	set_perm_stat( "karma", 9);
    set ("max_hp", 400);
    set ("max_sp", 0);
    set ("hit_points",400);
    set ("spell_points", 0);
    set ("wealth", ([ "copper": 0 ]) );
    set ("gender", "male");
    set ("natural_weapon_class1", 10);
    set ("natural_armor_class", 5);
    set ("natural_min_damage1", 10);
    set ("natural_max_damage1", 20);
    set ("aggressive",1);
    set ("weight", 200);
    set ("exp_reward",1000);
    set ("unit", "ֻ");
    set_c_verbs( ({"ץ"}) );
}
