#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron blade", "����" );
	add( "id", ({ "blade" }) );
	set_short( "����" );
	set_long(
		"����һ�����������ɵĵ��ӣ������е��������ġ�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "value", ({ 220, "silver" }) );
}
