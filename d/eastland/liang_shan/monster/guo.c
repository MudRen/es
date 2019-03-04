#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(14);
	set_name( "Guo Sheng", "��ʢ" );
	add("id",({"guo","sheng"}));
	set_short( "��ʢ" );
	set_long(
		"��ʢ������ʹ��Ĵ������ˣ����°׼ף���ʹ���컭ꪣ�Ϊ\n"
		"��ɽ�����С�뽫��Զ̽����ͷ�죬���ճ��ڡ�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_perm_stat( "str", 21 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 12 );
	set_skill( "polearm", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "wealth/gold", 50 );
	set( "special_defense", (["magic": 20 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 10 );

	wield_weapon( TWEAPON"polearm" );
        equip_armor( TARMOR"white_armor");
        equip_armor( TARMOR"bandit_armor");
}
