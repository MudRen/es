#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "highsteel shield", "��ִ��" );
	add( "id", ({ "shield" }) );
	set_short( "a highsteel shield", "��ִ��" );
	set_long(
		"You see a large highsteel shield.\n",
		"����һ��������ɵĴ�ܣ�������ʮ�ּ�����á�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "materia", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 70 );
	set( "value", ({ 610, "silver" }) );
}
