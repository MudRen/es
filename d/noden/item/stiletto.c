#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bloody stiletto", "Ѫ��С��" );
	add( "id", ({ "stiletto" }) );
   set_short( "Ѫ��С��" );
	set_long(
		"����һ��մ��Ѫ���ķ���С�� .... С�ģ��������ָ��\n"
	);
	set( "unit", "��" );
	setup_weapon( "dagger", 16, 6, 14 );
	set( "weight", 30 );
	set( "bleeding", 25 );
	set( "second", 1 );
	set( "value", ({ 630, "silver" }) );
}
