#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level( 3 );
	set_name( "old gardener", "��԰��" );
	add( "id", ({ "gardener" }) );
	set_short( "��԰��" );
	set_long(
		"��λ԰��������Ѿ������ˣ���������Ȼ���ڵ����޼���ľ��\n"
	);
	set( "race", "centaur" );
	set( "gender", "male" );
	set_skill( "shortblade", 40 );
	set_skill( "parry", 30 );
	set( "alignment", 400 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 5 );

	obj = new( "/d/noden/nodania/obj/scissors" );
	obj->move( this_object() );
	wield_weapon( obj );
}
