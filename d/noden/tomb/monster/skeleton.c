#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(6);
	set_name( "skeleton", "������" );
   set_short( "������" );
	set_long(
		"���������ȫ������ֻʣ�׹ǣ������㷢�������۾�������˸��\n"
		"��ɫ�Ĺ�â....��\n"
	);
   set( "race", "undead" );
	set_perm_stat("str", 6);
	set_skill("longblade", 20 );
	set_skill("parry", 20);
	set_skill("block",20);

	set( "alignment", -1000 );
	set( "natural_armor_class", 30);
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage", 4 );
	set( "natural_max_damage", 6 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
   set( "unbleeding", 1 );
	set( "wealth/gold", 5 );

	ob1 = new( "/d/noden/tomb/obj/sword" );
	ob1->move( this_object() );
	wield_weapon(ob1);
	ob2 = new( "/d/noden/tomb/obj/buckler" );
	ob2->move( this_object() );
	equip_armor(ob2);
	ob3 = new( "/d/noden/tomb/obj/amulet" );
	ob3->move( this_object() );
	equip_armor(ob3);
}
