#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Zhe Bao", "解宝" );
	add("id",({"zhe","bao"}));
	set_short( "解宝" );
	set_long(
		"他的外号是双尾蝎，解珍是他哥哥，性烈似火，与解珍同时落草，为梁\n"
		"山泊步军头领．如果你不想死的话，最好别去招惹他。\n"
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
