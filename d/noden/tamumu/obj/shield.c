#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "tower shield", "���Ͷ�" );
	add( "id", ({ "shield" }) );
	set_short( "���Ͷ�" );
	set_long(
	      "�������Ͷܷǳ����أ����滹�������������ķ��š�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "heavy_metal" );
	set( "armor_class", 6 );
	set( "weight", 250 );
	set( "special_defense", ([ "fire":2, "energy":-2 ]) );
	set( "value", ({ 500, "silver" }) );
}
