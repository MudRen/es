#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black leggings", "��ɫ��ϥ" );
	add( "id", ({ "leggings" }) );
	set_short( "��ɫ��ϥ" );
	set_long(
		"����һ����ɫ�ĵĻ�ϥ������������ʲ�����ɵġ�\n"
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "light_metal" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}
