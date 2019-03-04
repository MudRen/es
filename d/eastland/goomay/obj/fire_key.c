#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "steel seal", "���ַ�ӡ" );
	add( "id", ({ "key","seal" }) );
	set_short( "a steel seal", "���ַ�ӡ" );
	set_long(
		"A magic seal made by high steel.\n",
		"����һ�����ɻ����εĴ��ַ�ӡ��������ԡ���ĳ�����\n"
	);
	set( "unit", "��" );
	set( "to_lock", "FIRE_ELEMENT_KEY" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
