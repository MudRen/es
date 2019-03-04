#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "massive bo", "大石棒" );
	add( "id", ({ "bo" }) );
	set_short( "大石棒" );
	set_long(
		"这是一根很重的大石棒，是野蛮人战士惯用的武器。\n"
	);
	set( "unit", "根" );
	setup_weapon( "bo", 30, 15, 35 );
	set( "nosecond", 1 );
	set( "weight", 250 );
	set( "value", ({ 80, "silver" }) );
}
