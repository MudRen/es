#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "deer plate","¹Ƥ����" );
	add( "id", ({ "plate", "platemail", "mail" }) );
	set_short( "¹Ƥ����" );
	set_long(
		"����һ�ײ����������������ļ���, ν֮¹Ƥ���Ρ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
        set("material","leather");
	set( "armor_class", 28 );
	set( "weight", 180 );
	set( "value", ({ 1930, "silver" }) );
}
