#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long blade", "����" );
	add( "id", ({ "blade", }) );
	set_short( "����" );
	set_long(
		"���ǰ�������ɮʹ�õĳ���, ��������, �������г����ı�����\n" 
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 130 );
	set( "weapon_class", 22 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 490, "silver" }) );
}
