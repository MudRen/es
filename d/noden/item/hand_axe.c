#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "hand axe", "短斧" );
	add( "id", ({ "axe" }) );
   set_short( "短斧" );
	set_long(
		"这是一把小型的狩猎用短斧。\n"
	);
	set( "unit", "把" );
	setup_weapon( "axe", 5, 2, 9 );
	set( "weight", 60 );
	set( "value", ({ 30, "silver" }) );
}
