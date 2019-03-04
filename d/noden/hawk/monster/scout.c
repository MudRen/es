// /d/noden/hawk/monster/scout.c
#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(9);
	set_name("hawkman scout", "�������ڱ�");
	add( "id", ({"hawkman", "scout"}) );
	set_short("�������ڱ�");
	set_long(
		"�㿴��һλ��������ڱ������㿿������ʱ�����û��ɵ��۹�����㡣\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 6 );
	set_perm_stat( "str", 11 );
	set_perm_stat( "dex", 14 );
	set_skill( "thrusting", 50 );
	set_skill( "parry", 45 );
	set_skill( "dodge", 30 );

	ob1 = new("/d/noden/hawk/weapon/long_spear");
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new("/d/noden/hawk/armor/leather_armor" );
	ob2->move( this_object() );
	equip_armor( ob2 );
}
