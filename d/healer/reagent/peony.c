#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "peony", "芍药" );
set("no_sale",1);
	set_short( "芍药" );
	set_long(
		"这是由芍药的叶子晒乾制成的药材。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "PEONY" );
	set( "unit", "包" );
        set( "weight", 2 );
	set( "savour","acidity");
	set( "effect","weak");
	set( "frequency",1);
	set( "difference",3);
	set( "value", ({ 40, "silver" }) );
}
