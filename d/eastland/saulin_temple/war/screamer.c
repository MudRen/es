
#include "saulin_war.h"

inherit War;

void create()
{
        ::create();
        set_level(7);
        set_name( "screamer", "С��" );
        set_short( "С��" );
        set_long(
                "һ���ͷ��Եĺ��ӣ�ֻ���ֺ��ֽе�ҡ���ź���\n"
        );
        set( "moving", 1 );
        set( "speed", 30 );
//	set( "wimpy", 40 );
        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 10 );
        set("alignment",-200);
        set_perm_stat( "dex", 10 );
        set_perm_stat( "str", 5 );
	set_perm_stat( "int", 11 );
	set_perm_stat( "con", 5 );
        set_perm_stat( "piety", 4);
        set_perm_stat( "karma", 11);
        set ("max_hp", 155);
        set ("hit_points", 155);
        set( "race", "halfling" );
        set( "gender", "male" );
        set("natural_armor_class",22);
        set("natural_defense_bonus",5);
        set_skill("axe",60);
        wield_weapon(Obj"battle_axe");
        equip_armor(Obj"short_cloth");
}
