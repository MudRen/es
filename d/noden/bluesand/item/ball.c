#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "hankra ball", "������֮��" );
	add( "id", ({ "ball" }) );
   set_short( "������֮��" );
	set_long(
		"������֮��������һ����͵Ĺ�â����˵�����ֹ�â������ġ��ǻ۵�\n"
		"˼����Զ�ŵĴ��ڡ�\n"
	);
	set( "unit", "��" );
	set( "light", 1 );
	set( "weight", 70 );
	set( "value", ({ 300, "silver" }) );
	set( "no_sale", 1 );
}
