#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "key", "�߲�Կ��" );
	add( "id", ({ "key" }) );
	set_short( "�߲�Կ��" );
	set_long(
		"����һ���߲ʵ�Կ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "TOMBKEY_2" );
	set( "weight", 5 );
	set( "value", ({ 100, "copper" }) );
	set( "no_sale", 1 );
}
