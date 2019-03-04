#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel helm", "�ֿ�" );
	add( "id", ({ "helm" }) );
	set_short( "a steel helm", "�ֿ�" );
	set_long(
		"You see a steel helm with protective hood.\n",
		"����һ��Բ���ĸ���ͷ����\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set("material","heavy_metal");
	set( "weight", 60 );
	set( "armor_class", 5 );
	set( "value", ({ 240, "silver" }) );
}
