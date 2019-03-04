#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(8);
	set_name( "pirate warrior", "����սʿ" );
	add( "id", ({ "pirate", "warrior" }) );
   set_short( "����սʿ" );
	set_long(
		"�㿴��һ������սʿ�������۾����Ĵ���������Ҫ��һЩ�������ļһ��ܡ�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 14 );
	set_perm_stat( "dex", 11 );
	set_skill( "dodge", 50 );
	set_skill( "dagger", 50 );
	set_skill( "tactic", 50 );
	set( "tactic", "berserk" );
	set( "killer", 1 );
	set( "pursuing", 1 );
	set( "wealth/silver", 300 );
	set( "alignment", -400 );
	set_natural_armor( 40, 8 );
	set_natural_weapon( 8, 6, 6 );

	wield_weapon( "/d/noden/bluesand/item/cutlass" );
}
