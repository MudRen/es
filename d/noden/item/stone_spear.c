#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "stone spear", "ʯ��ì" );
	add( "id", ({ "spear" }) );
   set_short( "ʯ��ì" );
	set_long(
		"һ��ľ�ʳ�����ì�����ļ������ʯͷĥ����ɵġ�\n"
	);
	set( "unit", "��" );
	set( "type", "polearm" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 15 );
	set( "weight", 70 );
	set( "value", ({ 120, "silver" }) );
}
