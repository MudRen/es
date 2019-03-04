#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3, ob4;

	::create();
	set_level(16);
	set_name("Juraken", "������");
	add( "id", ({"pontiff"}) );
	set_short("�������̴��˾ ������");
	set_long(@CLONG
����������������˳��úܸߣ�һ��������ɫ���������ϴӱ��ӵ�������һ
���ܿ��µ��˺ۡ����������Ŀ��������ʱ��һ��Ī���ĺ���ʹ�������
�˽⵽: ��һ��Ǹ����򵥵����
CLONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -1500 );
	set( "natural_armor_class", 30 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 10 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_skill( "blunt", 100 );
	set_skill( "dodge", 90 );

	ob1 = new( "/d/noden/hawk/obj/crimson_scepter" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/hawk/obj/crimson_robe" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/hawk/obj/crimson_amulet" );
	ob3->move( this_object() );
	equip_armor( ob3 );

	ob4 = new( "/d/noden/hawk/obj/crimson_ring" );
	ob4->move( this_object() );
	equip_armor( ob4 );
}
