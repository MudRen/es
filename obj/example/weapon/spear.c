#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "spear", "��ì" );
	set_short( "a hunting spear", "�����ó�ì" );
	set_long(
		"A long spear designed for hunting boars.\n",
		"һ��������ɱҰ���õĳ�ì��\n"
	);
	set( "weapon_class", 6 );
	set( "type", "thrusting" );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "weight", 40 );
	set( "value", ({ 15, "gold" }) );
}
