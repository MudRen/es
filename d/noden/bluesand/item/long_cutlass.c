#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long cutlass", "���䵶" );
	add( "id", ({ "cutlass" }) );
   set_short( "���䵶" );
	set_long(
		"һ�ѳ������µ��䵶����������ʮ��������\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 17 );
	set( "weight", 70 );
	set( "value", ({ 320, "silver" }) );
}
