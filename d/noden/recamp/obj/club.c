#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "wooden club", "ľ��" );
	add( "id", ({ "club" }) );
   set_short( "ľ��" );
	set_long(
		"һ��������û��ʲ���ر��ľ�����ձ������ò������˼�Ȧ��\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 3 );
	set( "min_damage", 2 );
	set( "max_damage", 6 );
	set( "weight", 60 );
	set( "value", ({ 10, "silver" }) );
}
