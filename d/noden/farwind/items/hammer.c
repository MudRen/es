#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("hammer", "����");
	set_short("����");
	set_long(
		"���������һ�����������ô��պ�������õġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "blunt" );
	set( "weapon_class", 6 );
	set( "min_damage", 4 );
	set( "max_damage", 11 );
	set( "value", ({ 30, "silver" }) );
}
