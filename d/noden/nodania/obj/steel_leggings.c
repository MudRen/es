#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel leggings", "�ֻ�ϥ" );
	add( "id", ({ "leggings" }) );
	set_short( "�ֻ�ϥ" );
	set_long(
		"����һ�����ƵĻ�ϥ��\n"
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 100 );
	set( "value", ({ 1520, "silver" }) );
}
