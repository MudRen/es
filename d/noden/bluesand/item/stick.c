#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "����" );
	add( "id", ({ "stick" }) );
   set_short( "ľ�ʹ���" );
	set_long(
		"����һ���ü�Ӳ��ľͷ���ɵĹ��ȡ�\n"
	);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "weapon_class", 8 );
	set( "min_damage", 4 );
	set( "max_damage", 8 );
	set( "weight", 60 );
	set( "value", ({ 130, "silver" }) );
}
