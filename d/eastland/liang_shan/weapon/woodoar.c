#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("wood oar", "��ľ��");
	add("id",({"oar"}));
	set_short("��ľ��");
	set_long(
		"����һ����ľ�ƵĴ󴬽�����������һ�¿ɲ����档\n"
	);
	set( "unit", "��" );
	set( "weight", 170 );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 12 );
	set( "max_damage", 23 );
	set( "value", ({ 610, "silver" }) );
}
