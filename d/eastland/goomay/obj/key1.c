#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "iron key", "铁钥匙" );
	add( "id", ({ "key" }) );
	set_short( "an iron key", "铁钥匙" );
	set_long(
		"A rusty iron key.\n",
		"这是一把有些生绣的铁钥匙，看起来好像是锁牢门的。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "JAIL_DOOR" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
