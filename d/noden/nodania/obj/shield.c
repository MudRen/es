#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel shield", "�ֶ�" );
	add( "id", ({ "shield" }) );
	set_short( "�ֶ�" );
	set_long(
		"һ���������ҫ�۵ĸֶܡ�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 100 );
	set( "value", ({ 1130, "silver" }) );
}
