#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "skull glaive", "鬼头刀" );
	add( "id", ({ "glaive" }) );
   set_short( "鬼头刀" );
	set_long(
		"这是一把沈重的大刀，刀柄上刻著一个凶恶狰狞的鬼头。\n"
	);
	set( "unit", "把" );
	set( "weight", 150 );
	setup_weapon( "longblade", 26, 11, 29 );
	set( "bleeding", 5 );
	set( "value", ({ 72, "gold" }) );
}
