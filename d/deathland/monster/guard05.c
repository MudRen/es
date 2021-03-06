#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(15);
	set_name( "graveyard guard", "墓场守卫" );
	add("id",({"guard"}));
	set_short( "a graveyard guard", "墓场守卫" );
	set_long(
		"a holy guard.\n"
		"一个守护著矮人皇陵的守卫者,他很尽忠於他的任务.\n"
	);
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 29 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 26 );
	set_skill( "dodge", 95 );
	set_skill( "parry", 95 );
	set_natural_armor(40,20);
 	set_natural_weapon(15,5,15);
    set( "special_defense", (  ["all":30, "none": 30]  ) );
    set ("aim_difficulty",([ "critical": 30 ,"vascular": 30, "weakest": 30 ]) );
    equip_armor(Armour"/plate05");
    set_skill("longblade",100);
    wield_weapon(Weapon"/sword02");
}

