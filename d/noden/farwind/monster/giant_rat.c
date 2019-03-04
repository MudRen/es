#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "giant rat", "������" );
	add( "id", ({ "rat" }) );
	set_short( "������" );
	set_long(
		"һֻ�޴�������㻳����������û����һֻè�ܴ�Ӯ��ֻ����\n"
	);
	set_perm_stat("dex", 5 );
	set_perm_stat("str", 7 );

	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "unit", "ֻ" );
	set( "natural_armor_class", 18 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set( "max_hp", 100 );
	set( "hit_points", 100 );
}
