#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "prisoner", "����" );
	set_short( "����" );
	set_long(
		"һ���������ܿ����ļһ����ãȻ���������㡣\n"
	);
	set( "unit", "��" );
	set( "gender", "male" );
	set_skill( "dodge", 40 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 12 );
#include <replace_mob.h>
}
