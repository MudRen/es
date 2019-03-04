#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "morning star", "����ǹ" );
	add( "id", ({ "star" }) );
   set_short( "����ǹ" );
	set_long(
		"A huge heavy morning star.\n",
		"һ���ִ����ص�����ǹ�����ⶫ���򵽿ɲ��Ǻ���ġ�\n"
	);
	set( "type", "chain" );
	set( "weapon_class", 19 );
	set( "min_damage", 14 );
	set( "max_damage", 28 );
	set( "weight", 180 );
	set( "value", ({ 420, "silver" }) );
}
