#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "mikira potion", "米吉拉药水" );
	add( "id", ({ "potion", "mikira" }) );
	set_short( "米吉拉药水" );
	set_long(
		"这瓶药水上面标示著: 「米吉拉」，旁边注明: 医疗轻伤用。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
