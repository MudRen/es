#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze staff", "��ͭ����" );
	add( "id", ({ "staff" }) );
	set_short( "��ͭ����" );
	set_long( "����һ������ͭ���ɵ����ȣ��������൱���ء�\n");
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 140 );
	set( "value", ({ 240, "silver" }) );
}
