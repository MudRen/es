#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "diamond key", "��ʯԿ��" );
	add( "id", ({ "key" }) );
	set_short( "��ʯԿ��" );
	set_long(
		"��������ʯ��ĥ������Կ�ס�\n"
	);
	set( "to_lock", "DIAMONDKEY" );
	set( "weight", 3 );
	set( "value", ({ 50, "silver" }) );
	set( "no_sale", 1 );
}
