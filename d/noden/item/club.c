#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "massive club", "��ľ��" );
	add( "id", ({ "club" }) );
   set_short( "��ľ��" );
	set_long(
		"����һ�������ɲ��ֵľ�ľ����\n"
	);
	set( "unit", "��" );
	setup_weapon( "blunt", 25, 12, 29 );
	set( "weight", 330 );
	set( "value", ({ 30, "silver" }) );
}
