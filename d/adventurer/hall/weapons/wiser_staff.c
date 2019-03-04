#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("wiser staff", "����֮��");
	add( "id", ({ "staff" }) );
	set_short("a wiser staff", "����֮��");
	set_long(
		"This is a wiser staff. Old adventurers love such staff as\n"
		"their weapon.\n",
		"����һ������֮�ȣ�ͨ�������ϵ�ð�������������������\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 70 );
	set( "value", ({ 430, "silver" }) );
}
