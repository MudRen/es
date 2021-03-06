#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "chuan chiung", "川芎" );
           set("no_sale",1);
	add("id", ({"chuan","chiung"}) );
	set_short( "川芎" );
	set_long(
		"这是一包用来制药的川芎。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "CHUAN_CHIUNG" );
	set( "unit", "包" );
        set( "weight", 1 );
	set( "savour","acrimony");
	set( "effect","simple_poison");
	set( "duration",2);
	set( "damage",2);
	set( "value", ({ 50, "silver" }) );
}
