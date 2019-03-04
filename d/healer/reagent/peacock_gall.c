#include <mudlib.h>
inherit "/std/reagent.c";


void create()
{
	set_name( "peacock's gall", "孔雀胆" );
	add( "id", ({"gall"}) );
	set_short( "孔雀胆" );
	set_long(
		"这是一颗绿色的孔雀胆,具有强烈的毒性。\n"
		"如果你不怕死的话,可以尝尝(taste)它。\n"
	);
           set("no_sale",1);
	set( "unit", "颗" );
	set( "ident", "PEACOCK_GALL" );
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
        set ( "effect","simple_poison");
        set ( "duration",2);
        set ( "damage",40);
}

