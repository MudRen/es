#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "hand axe", "�̸�" );
	add( "id", ({ "axe" }) );
   set_short( "�̸�" );
	set_long(
		"����һ��С�͵������ö̸���\n"
	);
	set( "unit", "��" );
	setup_weapon( "axe", 5, 2, 9 );
	set( "weight", 60 );
	set( "value", ({ 30, "silver" }) );
}
