#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "short sword", "�̽�" );
	add( "id", ({ "sword" }) );
   set_short( "�̽�" );
	set_long(
		"һ�ѱ��������̽��Ķ̽���������������������\n"
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
	set( "weapon_class", 8 );
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 30 );
	set( "value", ({ 75, "silver" }) );
}
