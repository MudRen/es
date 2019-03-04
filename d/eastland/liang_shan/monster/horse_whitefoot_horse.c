#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(15);
	set_name( "whitefoot_horse", "̤ѩ����" );
	add( "id", ({ "horse" }) );
	set_short(  "̤ѩ����" );
	set_long(
		"һֻ��׳�ĺ�ɫ����������ֻ��ȴ�ǰ׵ġ�\n" );
	set( "unit", "ֻ" );
	set_perm_stat( "int", 10 );
	set_perm_stat( "str", 22 );
	set( "natural_armor_class", 70 );
	set( "natural_weapon_class1", 40 );
	set( "natural_min_damage1", 25 );
	set( "natural_max_damage1", 35 );
	set( "alignment", 100 );
	set( "max_load", 2450 );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_c_verbs( ({  "%s�˶�ѩ�㣬ƬƬѩ������%s", "%s��βһ˦��һ������ֱ��%s" }) );

}

void init()
{
//	monster::init();
	mount::init();
}