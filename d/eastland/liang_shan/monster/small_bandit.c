#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(7);
	set_name( "mountain thief", "山贼" );
	add( "id", ({ "thief", "bandit" }) );
	set_short( "山贼" );
	set_long(
		"这个山贼一副贼头贼脑的样子，八成刚干了什麽坏事回来。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -700 );
	set_perm_stat( "str", 14 );
	set_perm_stat( "dex", 8 );
	set_perm_stat( "kar", 2 );
	set_skill( "longblade", 40 );
	set_skill( "parry", 40 );
	set_skill( "dodge", 20 );
	set( "hit_points", 190 );
	set( "max_hp", 190 );
	set( "wealth/gold", 18 );
	set( "special_defense", (["all": 10 ]) );
	set( "pursuing", 1 );
	set( "wimpy", 20 );
	set_natural_weapon( 4, 4, 4 );
	set_natural_armor( 20, 8 );

	wield_weapon( TWEAPON"poblade" );
}
