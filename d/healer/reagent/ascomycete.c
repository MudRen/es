#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ascomycete", "付子菌" );
	add( "id", ({"reagent"}) );
	set_short("付子菌" );
	set_long(
		"这堆付子菌表面成黑色, 还闪烁著一些鳞光。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "ASCOMYCETE" );
	set( "unit", "堆" );
        set( "weight", 1 );
	set( "effect","slow");
	set( "frequency",5);
	set( "difference",4);
	set( "value", ({ 50, "silver" }) );
}
