#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastard blade", "���ֽ䵶" );
	add( "id", ({ "blade" }) );
	set_short( "���ֽ䵶" );
	set_long(
		"����һ���þ������ɵĳ�����䵶�����������޺��õ��ӹ��õı��С�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 178 );
	set( "nosecond", 1 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "value", ({ 600, "silver" }) );
}
