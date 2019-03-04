#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "shou-lin pill", "ÓñÁéÉ¢" );
	add( "id", ({ "pill" }) );
	set_short( "ÓñÁéÉ¢" );
	set_long(
		"ÓñÁéÉ¢ÄËÉÙÁÖÄÚ·şÖÎÉËÁ¼Ò©\n" 
	);
	set_healing( 40 );
	set( "no_sale", 1 );
	set( "weight", 5 );
	set( "value", ({ 10, "gold" }) );
	set( "medication", 35 );
	set( "effect_critical", 75 );
}
