#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "tiger's bone", "虎骨" );
         set("no_sale",1);
	add( "id", ({ "bone" }) );
	set_short( "虎骨" );
	set_long(
                "这是老虎的头骨, 可以做为一种药材。你可以尝尝(taste)看。\n"
	);
    set( "ident","BONE");
	set( "unit", "块" );
        set( "weight",3 );
	set( "savour","acidity");
	set( "value", ({ 300, "silver" }) );
}
