#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "prisoner", "����" );
	set_short( "����" );
	set_long("һ���������ܿ����ļһ����ãȻ���������㡣\n"
	);
	set( "unit", "��" );
	set( "gender", "male" );
	set( "race", "human" );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 18 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
}
