#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
   set_name( "cop", "������Ա" );
   set_short( "������Ա" );
	set_long(
        "������ɳ�۵ľ�����Ա, ר������������ӡ�\n"
	);
	set( "race", "lizardman" );
	set( "gender", "male" );
   set( "alignment", 600 );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 13 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );
	set( "tactic", "assault" );
	set( "wealth/gold", 25 );
   set_natural_armor( 40, 20 );

	wield_weapon( "/d/noden/bluesand/item/long_cutlass" );
	equip_armor( "/d/noden/bluesand/item/boots" );
}

