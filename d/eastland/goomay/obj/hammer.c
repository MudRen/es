#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("hammer", "����");
	set_short("an iron hammer", "����");
	set_long(
		"This is a regular hammer for blacksmith.\n",
		"���������һ���������������õġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "blunt" );
	set( "weapon_class", 6 );
	set( "min_damage", 4 );
	set( "max_damage", 11 );
	set( "value", ({ 30, "silver" }) );
}
