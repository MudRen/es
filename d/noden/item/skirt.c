#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "worn skirt", "旧裙子" );
	seteuid(getuid());
	add( "id", ({ "skirt" }) );
   set_short( "旧裙子" );
	set_long(
		"这件裙子已经又破又旧了，但是看起来仍然很乾净。\n"
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 2 );
	set( "weight", 30 );
	set( "value", ({ 13, "silver" }) );
}
