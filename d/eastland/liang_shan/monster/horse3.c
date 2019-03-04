#include "../takeda.h"

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(8);
	set_name( "flower horse", "С����" );
	add( "id", ({ "horse" }) );
	set_short( "С����" );
	set_long(
		"һֻɫ�ʰ�����С�����������Ǻܴ�����ӡ�\n" );
	set( "unit", "ֻ" );
	set( "value", ({ 100 , "silver" }));
	set( "weight",60);
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 13 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 );
	set( "alignment", 50 );
	set( "max_load", 1550 );
	set_limbs( ({ "head", "body", "feet", "tail" }) );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_verbs( ({ "kick" }) );
	set_c_verbs( ({  "%s�˶�Сѩ�㣬ֱ��%s", "%sС��βһ˦��ɨ��%s" }) );

}

void init()
{
	mount::init();
}
