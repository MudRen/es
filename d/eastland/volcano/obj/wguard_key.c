#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "guardroom key", "������Կ��" );
	add( "id", ({ "key" }) );
	set_short( "������Կ��" );
	set_long(
		"���ǰ����忴���ҵ�Կ�ס�\n"
	);
	set( "to_lock", "WGUARD" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
