#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "fire key", "����֮Կ" );
	add( "id", ({ "key" }) );
	set_short( "a fire key", "����֮Կ" );
	set_long(
		"A magic key with fire shape.\n",
		"����һ�����ɻ����ε�Կ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "FIRE_ELEMENT_KEY2" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
