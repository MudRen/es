#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "iron key", "��Կ��" );
	add( "id", ({ "key" }) );
	set_short( "an iron key", "��Կ��" );
	set_long(
		"A rusty iron key.\n",
		"����һ����Щ�������Կ�ף������������������ŵġ�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "JAIL_DOOR" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
