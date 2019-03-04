#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(14);
	set_name( "jailor", "��������" );
	add( "id", ({ "tamumu jailor", "tamumu" }) );
	set_short( "��ķķ��������" );
	set_long("��һ￴�������׺�����ò�����ȥ�����ɣ�\n"
	);
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set_perm_stat( "str", 18 );
	set_skill( "axe", 90 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -800 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 20 );
	set( "wealth/gold", 20 );

	ob1 = new( "/d/noden/tamumu/obj/axe" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/noden/tamumu/obj/jail_key" );
	ob2->move( this_object() );
}
