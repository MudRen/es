#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "skeleton key", "��Կ��" );
	add( "id", ({ "key" }) );
	set_short( "a skeleton key", "��Կ��" );
	set_long(
		"A skelton key.\n",
		"����һ�ѹ�ͷԿ��,����д����һ�ѷ���\n"
	);
	set( "unit", "��" );
	set( "to_lock", "ECHO_MINE_CHEST" );
	set( "weight", 5 );
	set( "value", ({ 120, "silver" }) );
	set( "no_sale", 1 );
}
