#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "etheral cutlass", "�����䵶" );
	add( "id", ({ "cutlass" }) );
   set_short( "�����䵶" );
	set_long(
		"һ����˸���İ����ε��䵶������������ƮƮ�ģ��о�����������\n"
	);
	set( "unit", "��" );
   set( "type", "shortblade" );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 16 );
	set( "weight", 5 );
	set( "value", ({ 320, "silver" }) );
}
