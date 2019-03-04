#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(12);
	set_name("altar guard", "��̳����");
	add( "id", ({"guard"}) );
         set_short("��̳����");
	set_long(
		"�����̳�������ø߸����ݵģ����ϻ�����һ��������ʺ�ɫ���ۡ�\n"
	);
	set( "gender", "male" );
	set( "alignment", -500 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 9 );
	set( "aggressive", 1 );
	set_perm_stat( "str", 14 );
	set_perm_stat( "dex", 14 );
	set_perm_stat( "int", 25 );
	set_skill( "longblade", 60 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 50 );

	ob1 = new( "/d/noden/hawk/obj/crimson_sword" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/hawk/obj/crimson_robe" );
	ob2->move( this_object() );
	equip_armor( ob2 );
}
