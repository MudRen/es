#include <races.h>

inherit RACE_INSECT;

void create()
{
	::create();
	set_level(2);
	set_name( "bamboo beetle", "���" );
	add("id", ({"beetle"}) );
	set_short( "���" );
	set_long(
		"һֻС��ꡣ\n"
	);
	set_perm_stat( "str", 5 );

	set( "unit", "ֻ" );
	set( "alignment", 150 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4);
	set( "natural_max_damage1", 8);
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"С����ѽ�ɵģ���������Сʱ��\n" }) );
	set_c_verbs( ({ "%s�ý���%sһ��", "%s�ſ���������%sҧȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ų�", "�׿�" }) );
}
