#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(17);
	set_name( "honor guard", "��������" );
	add("id",({"guard"}));
	set_short( "a honor guard", "��������" );
	set_long(
		"a holy guard.\n"
		"һ���ػ�������ʥ�صĹ�������.\n"
	);
	set( "gender", "male" );
	set( "alignment", 1200 );
	set_perm_stat( "dex", 27 );
	set_perm_stat( "str", 26 );
	set_perm_stat( "kar", 18 );
	set("max_hp",550);
	set("hit_points",550);
	set_skill( "dodge", 90 );
	set_skill( "parry", 100 );
	set_natural_armor(50,30);
 	set_natural_weapon(18,5,25);
    set( "special_defense", (  ["all":35, "none": 25]  ) );
    set ("aim_difficulty",([ "critical": 30 ,"vascular": 35, "weakest": 20 ]) );
    equip_armor(Armour"/plate05");
    equip_armor(Armour"/boots02");
    equip_armor(Armour"/gloves02");
    set_skill("longblade",100);
    wield_weapon(Weapon"/sword02");
}

