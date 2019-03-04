#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Zhe Zhen", "����" );
	add("id",({"zhe","zhen"}));
	set_short( "����" );
	set_long(
		"�����������ͷ�ߣ������ˣ��ⱦ�����ܵܣ�ԭ�ǵ����Ի�����ʹ�ֲ棬Ϊ��\n"
		"ɽ������ͷ�죮����㲻�����Ļ�����ñ�ȥ��������\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -220 );
	set_perm_stat( "str", 21 );
	set_perm_stat( "dex", 19 );
	set_perm_stat( "kar", 11 );
	set_skill( "thrusting", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 266 );
	set( "max_hp", 260 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 22 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 8 );

	wield_weapon( TWEAPON"fork" );
        equip_armor( TARMOR"tiger_cloth");
        equip_armor( TARMOR"panther_pants");
        equip_armor( TARMOR"black_hood");
}
