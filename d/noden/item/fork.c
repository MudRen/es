#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "hay fork", "���ݲ�" );
	add( "id", ({ "fork" }) );
   set_short( "���ݲ�" );
	set_long(
		"һ�����������ݶѳ�һ�ѵĲݲ档\n"
	);
	set( "unit", "��" );
	set( "type", "thrusting" );
	set( "weapon_class", 3 );
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 80 );
	set( "value", ({ 20, "silver" }) );

}
