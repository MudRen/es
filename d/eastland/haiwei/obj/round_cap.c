#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "round cap", "Բ��Сñ" );
	add( "id", ({ "cap" }) );
	set_short( "Բ��Сñ" );
	set_long("����һ����в����Բ��Сñ��������������Ǯ�˵�ñ�ӡ�\n");
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "cloth" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
