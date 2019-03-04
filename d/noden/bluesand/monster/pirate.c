#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(5);
	set_name( "pirate", "����ˮ��" );
   set_short( "����ˮ��" );
	set_long(
		"�㿴��һ�������³��������ĺ���ˮ�֡�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 8 );
	set_perm_stat( "dex", 6 );
	set_skill( "dodge", 40 );
	set_skill( "dagger", 40 );
	set_skill( "tactic", 40 );
	set( "tactic", "melee" );
	set( "killer", 1 );
	set( "wealth/silver", 70 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 6 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 4 );

	ob1 = new( "/d/noden/bluesand/item/dagger" );
	ob1->move(this_object());
	wield_weapon(ob1);
}
