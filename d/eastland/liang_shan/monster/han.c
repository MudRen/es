#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Han Tao", "����" );
	add("id",({"han","tao"}));
	set_short( "����" );
	set_long(
		"��������ǰ�ʤ���������ˣ�ʹһ����ľ�ã�Ϊ��ɽ�����С�뽫��Զ\n"
		"̽����ͷ�죮����㲻�����Ļ�����ñ�ȥ��������\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 320 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 11 );
	set_skill( "blunt", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 380 );
	set( "max_hp", 380 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 8 );

	wield_weapon( TWEAPON"woodoar" );
        equip_armor( TARMOR"black_cloth");
        equip_armor( TARMOR"blue_cloak");
        equip_armor( TOBJ"jail_key");
}
