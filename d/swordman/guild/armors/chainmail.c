#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "regular chainmail", "����" );
	add( "id", ({ "chain", "mail", "regular" }) );
	set_short( "��ʽ����" );
	set_long(
		"������׿��������أ�������Ե����ṩ�൱����ı�����\n"
	);
	set( "unit", "��" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 15 );
	set( "value", ({ 400, "silver" }) );
}
