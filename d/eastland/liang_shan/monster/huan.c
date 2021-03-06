#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(15);
	set_name( "Huang Shin", "黄信" );
	add("id",({"huang","shin"}));
	set_short( "黄信" );
	set_long(
		"黄信外号镇三山，善使一把丧门剑，为梁山泊马军小彪将兼远探出哨头领，\n"
		"如果你不想死的话，最好别去招惹他。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 10 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 80 );
	set_skill( "dodge", 50 );
	set( "hit_points", 420 );
	set( "max_hp", 420 );
	set( "wealth/gold", 77 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 30, 10 );

	wield_weapon( TWEAPON"deathsword" );
        equip_armor( TARMOR"white_warcape");
        equip_armor( TARMOR"wool_hat");
        equip_armor( TARMOR"blue_cloak");
}
