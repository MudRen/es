#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron axe", "��師" );
	add( "id", ({ "axe" }) );
	set_short( "a iron axe", "��師" );
	set_long(
		"You see an iron axe for cut trees.\n",
		"����һ�Ѿ޴�İ師������һ�Ѵ����ӣ�û���������˿����ò�������\n"
	);
	set ("second",1);
	set( "unit", "��" );
	set( "weight", 200 );
	setup_weapon( "axe", 35, 15, 30 );
	set( "value", ({ 420, "silver" }) );
}
