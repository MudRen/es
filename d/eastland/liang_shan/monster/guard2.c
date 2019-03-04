#include <../takeda.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(13);
	set_name( "Crab warrior", "з��" );
	add( "id", ({ "warrior", "crab" }) );
	set_short( "Crab warrior", "з��" );
	set_long(
		"\n",
		"��һ��սʿ����������Ҫ�ػ���,��������׷������֮�����ߡ�\n"
	);
	set( "unit", "��" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 17 );
	set_skill( "shortblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "block", 90 );
	set( "aggressive", 1 );
        set ("natural_weapon_class1", 18);
        set ("natural_min_damage1", 8);
        set ("natural_max_damage1", 11);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",10);
        wield_weapon(TWEAPON"gurad_sword");
        equip_armor(TARMOR"guard_mail2");
        equip_armor(TARMOR"guard_shield");
}
