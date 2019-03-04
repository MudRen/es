#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(14);
	set_name( "Lu Fang", "����" );
	add("id",({"lu","fang"}));
	set_short( "����" );
	set_long(
		"�������С�º����̶���ˣ����º�ף���ʹ���컭ꪣ�Ϊ\n"
		"��ɽ�����С�뽫��Զ̽����ͷ�죬���ղ�����\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_perm_stat( "str", 21 );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "kar", 11 );
	set_skill( "polearm", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "wealth/gold", 50 );
	set( "special_defense", (["magic": 20 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 10 );

	wield_weapon( TWEAPON"polearm" );
        equip_armor( TARMOR"red_armor");
        equip_armor( TARMOR"bandit_armor");
}
