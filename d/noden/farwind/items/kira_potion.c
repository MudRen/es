#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "kira potion", "吉拉药水" );
	add( "id", ({ "potion", "kira" }) );
	set_short( "吉拉药水" );
	set_long(
		"这瓶药水上面标示著: 「吉拉」，旁边注明: 服用drink。\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 25 );
	set( "value", ({ 250, "silver" }) );
    set( "medication", 40 );
    set( "effect_critical", 90 );
}
