#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "hole wolf", "Ѩ��" );
	add( "id", ({ "wolf" }) );
	set_short( "Ѩ��" );
	set_long(
		"����һ�־�ס�ɽ��֮�е��ǡ� \n"
	);
	set_perm_stat( "str", 10 );
	set_skill( "dodge", 30 );

	set( "unit", "ֻ" );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 9 );
	set( "killer", 1 );

	set_c_verbs( ({ "%s��ǰצ����%s", "%s�ſ��������ݵ��죬��%sҧȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "β��", "�Ȳ�" }) );
#include <replace_mob.h>
}
