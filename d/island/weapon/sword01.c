#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "lizardman shortsword", "�����˶̽�" );
	add( "id", ({ "sword","shortsword" }) );
	set_short( "�����˶̽�" );
	set_long(@LONG
һ��ľ�ʽ����Ķ̽������ƺ������Ǻܷ��������ʺϿ�����
LONG
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
	set( "weapon_class", 15 );
	set( "min_damage", 8 );
	set( "max_damage", 19 );
	set( "weight", 90 );
	set( "value", ({ 150, "silver" }) );
}
