#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long spear", "��ì" );
	add( "id", ({ "spear" }) );
	set_short( "��ì" );
	set_long(
		"�����ì����һ֦��ľ������ĩ�˰���һ��������ʯ��Ƭ�Ƴɡ�\n"
	);
	set( "unit", "֦" );
	set( "weight", 90 );
	set( "type", "thrusting" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 14 );
	set( "value", ({ 180, "silver" }) );
}
