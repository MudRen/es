#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "grey rat", "������" );
	add( "id", ({ "rat" }) );
	set_short( "������" );
	set_long(
		"һֻ�ִ��ַʵĻ����󣬿��������ࡣ\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 3 );
	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 2 );
}
