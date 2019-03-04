#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "bucket", "大水桶" );
	set_short( "大水桶" );
	set_long(
		"这是神殿内用来浇菜用的大水桶，非常大，甚至人可以坐在里面。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
