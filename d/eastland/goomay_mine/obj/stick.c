#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "����" );
	add( "id", ({ "stick" }) );
   set_short( "����" );
	set_long(
		"����һ���ü�Ӳ��ľͷ���ɵĹ��ȣ�Ŀ�������ж�������\n"
		"����ʹ�õġ�\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 100 );
	set( "value", ({ 230, "silver" }) );
}
