#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "fat rat", "������" );
	add( "id", ({ "rat" }) );
	set_short( "������" );
	set_long(
		"һֻ���ʵĴ����󣬿���������һͷ��\n"
	);
	set_perm_stat("dex", 2 );
	set_perm_stat("str", 5 );

	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 4 );
	set( "max_hp", 50 );
	set( "hit_points", 50 );
}
