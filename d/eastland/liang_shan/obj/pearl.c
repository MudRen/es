#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Moon pearl", "ҹ����" );
	add( "id", ({ "pearl" }) );
	set_short( "moon pearl", "ҹ����" );
	set_long(
		".\n",
		"����һ�ź����Ĵ����飬�����λð�Ĺ�â���ݴ��Ǵ����\n"
		"�����¹⾫���Ľᾧ��\n"
	);
	set( "unit", "��" );
	set( "light", 1 );
	set( "weight", 30 );
	set( "value", ({ 3000, "silver" }) );
	set( "no_sale", 1 );
}
