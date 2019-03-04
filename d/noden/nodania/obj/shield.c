#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel shield", "¸Ö¶Ü" );
	add( "id", ({ "shield" }) );
	set_short( "¸Ö¶Ü" );
	set_long(
		"Ò»Ãæ²ÁµÃÉÁÁÁÒ«ÑÛµÄ¸Ö¶Ü¡£\n"
	);
	set( "unit", "Ãæ" );
	set( "type", "shield" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 100 );
	set( "value", ({ 1130, "silver" }) );
}
