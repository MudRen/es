#include <races.h>

inherit RACE_UNDEAD;

void create()
{
	::create();
	set_level(11);
	set_name( "tomb guard","Ĺ������" );
	add( "id", ({ "guard" }) );
	set( "right_guard", 1 );
	set_short( "Ĺ������" );
	set_long(
		"һ������Ĺ�ز����������ֵ�������\n"
	);
	set( "gender", "male" );
	set( "alignment", 400 );
	set_natural_armor( 30, 10 );
	set_natural_weapon( 5, 5, 5 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
	set_skill( "longblade", 60 );
	set_skill( "parry", 70 );
	set( "hit_points", 350 );
	set( "max_hp", 350 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 20 ]) );

	wield_weapon( "/d/eastland/easta/obj/longsword" );
	equip_armor( "/d/eastland/easta/obj/scale_mail" );
	equip_armor( "/d/eastland/easta/obj/brass_helm" );
}
