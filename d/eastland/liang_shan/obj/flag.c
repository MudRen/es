#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "small flag", "����" );
	add( "id", ({ "flag" }) );
	set_short( "a small flag", "����" );
	set_long(
		"This is the flag of bandit trainer.\n",
		"����һ��ָ��ɽ�������죬�������������е��Ľ��֣���������������\n"
		"��ɽͨ�����衣\n"
	);
	set( "weight", 3 );
	set( "value", ({ 3000, "silver" }) );
	set( "no_sale", 1 );
}
