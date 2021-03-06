#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "black lotus", "黑沼莲心" );
	add( "id", ({"lotus"}) );
	set_short( "黑沼莲心" );
	set_long(
		"黑沼莲心是由一种生长在沼泽中的莲子心晒乾制成的。色呈淡粉红,\n"
		"有些淡淡的香。你可以尝尝(taste)他的味道。\n"
	);
	set( "unit","包");
	set( "ident", "BLACK_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",3);
        set( "weight", 1 );
	set( "value", ({ 15, "silver" }) );
}

