#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "��������" );
	add( "id", ({ "saddle" }) );
	set_short(  "��������" );
	set_long(
		"����һ����������������ʿ�Ƕ���Ϊ�Լ��İ���ѡ�����ʵ�����\n" 
		);
	set( "type", "saddle" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "weight", 110 );
	set( "value", ({ 430, "silver" }) );
}
