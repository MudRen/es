#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel glaive", "��ִ�" );
	add( "id", ({ "glaive" }) );
	set_short( "a highsteel glaive", "��ִ�" );
	set_long(
		"You see a huge, heavy highsteel glaive. This is the regular\n"
		"weapon of soldiers guarding the Mumar Keep.\n",
		"����һ�Ѿ޴����ص���ִ󵶣����ر߽���ʿ������ʽ������\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 28 );
	set( "min_damage", 16 );
	set( "max_damage", 25 );
	set( "weight", 90 );
	set( "value", ({ 430, "silver" }) );
}
