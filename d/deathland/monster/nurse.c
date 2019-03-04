
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(7);
	set_name( "dwarf nurse", "���˻�ʿ" );
	add( "id", ({ "nurse", }) );
	set_short( "a dwarf nurse", "���˻�ʿ" );
	set_long(
		"NEED TRANSLATION.\n",
		"���𿴹����չ�Ӥ���Ļ�ʿ.\n"
	);
	set("alignment",300);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set_perm_stat( "str", 8 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "kar", 14 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 56 );
	set_skill( "anatomlogy", 55 );
	set( "aiming_loc", "weakest" );
	set("wealth",(["silver":200]) );
	set( "max_hp", 190 );
	set( "hit_points", 190 );
	set_natural_armor(37,3);
	set_natural_weapon(15,7,15);
	set( "alignment", 600 );
}
