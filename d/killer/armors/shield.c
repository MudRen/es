#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "large shield", "���Ͷ�" );
	add( "id", ({ "shield" }) );
	set_short( "���Ͷ�" );
	set_long(
		"��������ִ��ֺ��������Ϥ�ö��赲���˵ķ���������Ǹ������ѡ��\n"
	);
	set( "unit", "��" );
	set( "weight", 160 );
	set( "type", "shield" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 8 );
	set( "value", ({ 440, "silver" }) );
}
