#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "staff", "ľ��" );
	set_short( "a wooden staff", "ľ��" );
	set_long(
		"A long hard wooden staff.\n",
		"һ������Ӳ����������������ľ�ȡ�\n"
	);
	set( "weapon_class", 7 );
	set( "type", "blunt" );
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 30 );
	set( "value", ({ 10, "gold" }) );
}
