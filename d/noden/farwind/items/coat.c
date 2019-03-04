#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dirty coat", "脏外套" );
	add( "id", ({ "coat" }) );
	set_short( "脏外套" );
	set_long(
		"这件外套上满是污泥与油渍，还有一股浓浓的酒臭味。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 40 );
	set( "value", ({ 12, "silver" }) );
}
