#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty large sword", "��ʯ�޽�" );
	add( "id", ({ "sword" }) );
	set_short( "��ʯ�޽�" );
	set_long(
		"����һ���ð���ɫ��ʯ���ɵĵľ޽������Ǿ����츳����
�������ò����ġ�\n" );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 28 );
	set( "value", ({ 950, "silver" }) );
}


