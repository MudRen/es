#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Zhe Bao", "�ⱦ" );
	add("id",({"zhe","bao"}));
	set_short( "�ⱦ" );
	set_long(
		"���������˫βЫ������������磬�����ƻ������ͬʱ��ݣ�Ϊ��\n"
		"ɽ������ͷ�죮����㲻�����Ļ�����ñ�ȥ��������\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -220 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 11 );
	set_skill( "thrusting", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 260 );
	set( "max_hp", 260 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 8 );

	wield_weapon( TWEAPON"fork" );
        equip_armor( TARMOR"tiger_cloth");
        equip_armor( TARMOR"panther_pants");
        equip_armor( TARMOR"black_hood");
}
