#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dirty coat", "������" );
	add( "id", ({ "coat" }) );
	set_short( "������" );
	set_long(
		"����������������������գ�����һ��ŨŨ�ľƳ�ζ��\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 40 );
	set( "value", ({ 12, "silver" }) );
}
