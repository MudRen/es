#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "shou-lin pill", "����ɢ" );
	add( "id", ({ "pill" }) );
	set_short( "����ɢ" );
	set_long(
		"����ɢ�������ڷ�������ҩ\n" 
	);
	set_healing( 40 );
	set( "no_sale", 1 );
	set( "weight", 5 );
	set( "value", ({ 10, "gold" }) );
	set( "medication", 35 );
	set( "effect_critical", 75 );
}
