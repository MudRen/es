#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "short sword", "�̽�" );
	add( "id", ({ "sword" }) );
	set_short( "�����̽�" );
	set_long(
		"���ָ����̽���ŵ����ʿ�ŵ�����ǣ�����Я����������\n"
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
	set( "weapon_class", 11 );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "weight", 50 );
	set( "value", ({ 120, "silver" }) );
}
