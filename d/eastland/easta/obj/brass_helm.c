#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "brass helm", "ͭ��ñ" );
	add( "id", ({ "helm" }) );
	set_short( "ͭ��ñ" );
	set_long("����һ��Բ����ͭ�ƿ�ñ��\n");
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "weight", 60 );
	set( "armor_class", 4 );
	set( "value", ({ 340, "silver" }) );
}
