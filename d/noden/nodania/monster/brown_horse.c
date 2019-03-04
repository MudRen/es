#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	object saddle;

	::create();
	set_level(6);
	set_name( "brown horse", "��ɫ��" );
	add( "id", ({ "horse" }) );
	set_short( "��ɫ��" );
	set_long(
		"����һƥ�ߴ�ǿ׳����ɫ��\n" );
	set( "unit", "ƥ" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 10 );
	set( "alignment", 100 );
	set( "max_load", 1900 );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_c_verbs( ({ "%ş�����ȣ���%sһ��", "%s������������ǰ֫��%sһ�����ҵ�" }) );

	saddle = new( "/d/noden/nodania/obj/leather_saddle" );
	saddle->move( this_object() );
	equip_armor( saddle );
}

void init()
{
//	monster::init();
	mount::init();
}
