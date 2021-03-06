#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp moss", "沼泽苔" );
        set("no_sale",1);
	add( "id", ({"moss"}) );
	set_short( "some swamp moss", "沼泽苔" );
	set_long(
		"You see some green moss with dark spots.\n",
		"这是一种生长在沼泽地区的苔类，上面有一些黑色斑点。你可以尝尝(taste)看。\n"
	);
	set( "unit", "团" );
	set( "ident", "SWAMP_MOSS" );
	set( "effect","slow");
	set( "frequency",3);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
}
