#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snake skin", "��Ƥ����" );
	add( "id", ({ "skin" }) );
   set_short( "��Ƥ����" );
	set_long(
		"����һ������Ƥ���ɵ���ֻ��ף���������Ϊ��β�͵�����Ƶġ�\n"
	);
	set( "unit", "��" );
	set( "type", "tail" );
	set( "material", "leather");
	set( "armor_class", 3 );
	set( "weight", 60 );
	set( "value", ({ 40, "silver" }) );
}
