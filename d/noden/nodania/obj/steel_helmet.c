#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel helmet", "��ͷ��" );
	add( "id", ({ "helmet" }) );
	set_short( "��ͷ��" );
	set_long(
		"����һ�����Ƶ�ͷ�������滹�б��������������֡�\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 60 );
	set( "value", ({ 1520, "silver" }) );
}
