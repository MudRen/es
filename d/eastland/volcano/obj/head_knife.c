#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "sharp knife", "锐利小刀" );
	set_short( "锐利小刀" );
	set_long(
		"这是一把专门用来割头颅的小刀。\n"
	);
        add("id", ({"knife"}));
	set( "no_sale", 1 );
	set( "unit", "把" );
	set( "weight", 3 );
	set( "value", ({ 0, "silver" }) );
}
