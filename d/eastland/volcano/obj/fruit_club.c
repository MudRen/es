#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "fruit_club", "小槌子" );
	set_short( "小槌子" );
	set_long(
		"这是专门用来敲人参果用的槌子。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 5 );
	set( "value", ({ 1, "silver" }) );
}
