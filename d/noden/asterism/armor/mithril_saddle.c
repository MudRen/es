#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "��������" );
	add( "id", ({ "saddle" }) );
	set_short( "��������" );
	set_long(
		"����һ����������������Ƴɵ��������ṩ�����ʵ���˸о���\n" );
	set( "type", "saddle" );
        set("material","light_metal");
	set( "armor_class", 10 );
	set( "defense_bouns",2 );
	set( "weight", 120 );
	set( "value", ({ 950, "silver" }) );
}
