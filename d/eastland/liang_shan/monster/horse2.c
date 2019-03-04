#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(12);
	set_name( "whitefoot horse", "����̤ѩ" );
	add( "id", ({ "horse" }) );
	set_short( "����̤ѩ" );
	set_long(
		"һֻ��ɫ��С����������ֻ��ȴ�ǰ׵ġ�\n" );
	set( "unit", "ֻ" );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 18 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 25 );
	set( "alignment", 100 );
	set( "max_load", 2300 );
	set_limbs( ({ "head", "body", "feet", "tail" }) );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_verbs( ({ "kick" }) );
	set_c_verbs( ({  "%s�˶�ѩ�㣬ƬƬѩ������%s", "%s��βһ˦��һ������ֱ��%s" }) );

}

void init()
{
	mount::init();
}