#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "chain vest", "���ױ���" );
	add( "id", ({ "vest" }) );
	set_short( "���ױ���" );
	set_long(
		"һ�������������ñ���Ч�������ױ��ġ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 17 );
	set( "weight", 140 );
	set( "value", ({ 470, "silver" }) );
}
