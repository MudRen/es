#include <mudlib.h>

inherit "/d/eastland/easta/monster/easta_army";

void create()
{
	::create();
	set_level(11);
	set_name( "cityguard", "��ᰳ�����" );
	add( "id", ({ "guard" }) );
	set_short( "��ᰳ�����" );
	set_long(
		"�㿴��һ��������ᰳ�������\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 500 );
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
