#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("dagger", "ذ��");
	set_short("a short dagger", "��ذ��");
	set_long(
		"A fairly short dagger with sharp thin blade.\n",
		"һ��С�ɾ��µ�ذ�ס�\n"
	);
	set( "weapon_class", 7 );
	set( "type", "dagger" );
	set( "min_damage", 4 );
	set( "max_damage", 6 );
	set( "weight", 15 );
	set( "value", ({ 5, "gold" }) );
}
