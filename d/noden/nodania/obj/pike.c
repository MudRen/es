#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("pike", "��ǹ");
	set_short("��ǹ");
	set_long(
		"����һ���ڳ���ľ��ĩ��װ��ǹͷ�����������\n"
	);
	set( "unit", "��" );
	set( "weight", 60 );
	set( "type", "polearm" );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 16 );
	set( "nosecond", 1 );
	set( "value", ({ 500, "silver" }) );
}
