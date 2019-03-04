#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(11);
	set_name( "white horse", "��ɫ��" );
	add( "id", ({ "horse" }) );
	set_short( "��ɫ��" );
	set_long(
		"����һƥ�ߴ�ǿ׳�İ�ɫ��ͨ���԰���Ϊ�������ʿ��λ�����͡�\n" );
	set( "unit", "ƥ" );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 7 );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 19 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 21 );
	set( "alignment", 100 );
	set( "max_load", 2100 );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_c_verbs( ({ "%ş�����ȣ���%sһ��", "%s������������ǰ֫��%sһ�����ҵ�" }) );

	equip_armor("/d/noden/nodania/obj/mithril_saddle" );
}

void init()
{
//	monster::init();
	mount::init();
}
