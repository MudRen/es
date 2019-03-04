#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(10);
	set_name( "ghost pirate", "����" );
	add("id", ({"ghost", "pirate"}) );
   set_short( "����" );
	set_long(
		"�㿴��һ��ģ���Ĺ�Ӱ������һ�������䵶�ĺ�����Ӱ��\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 14 );
	set_skill( "dodge", 70 );
    set_skill( "shortblade", 70 );
	set_skill( "tactic", 70 );
	set( "tactic", "melee" );
	set( "killer", 1 );
	set( "wealth/silver", 270 );
	set( "max_hp", 250 );
	set( "hit_points", 250 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 12 );
	set_natural_weapon( 13, 6, 10 );

	wield_weapon( "/d/noden/bluesand/item/etheral_cutlass" );
}
