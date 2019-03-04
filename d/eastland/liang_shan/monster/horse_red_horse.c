#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(14);
	set_name( "red_horse", "��������" );
	add( "id", ({ "horse" }) );
	set_short( "��������" );
	set_long(
		"һֻ��ɫ��С��������Ƣ���ƺ���̫�á�\n" );
	set( "unit", "ֻ" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set( "natural_armor_class", 45 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 30 );
	set( "alignment", 10 );
	set( "max_load", 2300 );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_c_verbs( ({  "%s�˶�ǰ�㣬��ǰֱ��%s", "%s��β��һ˦��һ�ź���ɨ��%s" }) );

}

void init()
{
//	monster::init();
	mount::init();
}
