#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Han Tao", "韩滔" );
	add("id",({"han","tao"}));
	set_short( "韩滔" );
	set_long(
		"他的外号是百胜将，东京人，使一条枣木槊，为梁山泊马军小彪将兼远\n"
		"探出哨头领．如果你不想死的话，最好别去招惹他。\n"
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
