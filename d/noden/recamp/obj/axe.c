#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "iron axe", "����" );
	add( "id", ({ "axe" }) );
   set_short( "����" );
	set_long(
		"�������������Ȼ��һ�����⣬���Ǹ��в�����Ȼ�⻬������\n"
	);
	set( "unit", "��" );
	set( "type", "axe" );
	set( "weapon_class", 11 );
	set( "min_damage", 6 );
	set( "max_damage", 15 );
	set( "nosecond", 1 );
	set( "weight", 120 );
	set( "value", ({ 70, "silver" }) );
}
