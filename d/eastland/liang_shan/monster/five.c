#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Zhuan Shiao Wu", "阮小五" );
	add("id",({"zhuan","shiao","wu"}));
	set_short( "阮小五" );
	set_long(
		"阮小五外号短命二郎，小二是他哥哥，小七是他弟弟，本以打鱼维生，兄\n"
		"弟三人随吴用落草，现俱为水军头领。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -100 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 10 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 25 );
	set_skill( "dodge", 40 );

	set( "wealth/gold", 30 );
	set( "special_defense", (["all": 17 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );

	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
