#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "golden key", "��ɫԿ��" );
	add( "id", ({ "key" }) );
	set_short( "an golden key", "��ɫԿ��" );
	set_long(
		"A golden key.\n",
		"����һ�ѽ�ɫ��Կ��,������������ʯ\n"
	);
	set( "unit", "��" );
	set( "to_lock", "ECHO_DWARF_CITY_1" );
	set( "weight", 3 );
	set( "value", ({ 120, "silver" }) );
	set( "no_sale", 1 );
}
