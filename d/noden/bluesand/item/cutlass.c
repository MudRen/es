#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "cutlass", "�䵶" );
	add( "id", ({ "cutlass" }) );
   set_short( "�䵶" );
	set_long(
		"һ�Ѿ��µ��䵶����������ʮ��������\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 15 );
	set( "min_damage", 10 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 420, "silver" }) );
}
