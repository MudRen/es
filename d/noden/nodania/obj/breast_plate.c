#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel breastplate", "¸ÖĞØ¼×" );
	add( "id", ({ "plate", "breastplate" }) );
	set_short( "¸ÖĞØ¼×" );
	set_long(
		"Ò»¼ş²ÁµÃÉÁÁÁÒ«ÑÛµÄ¸ÖÖıĞØ¼×¡£\n"
	);
	set( "unit", "¼ş" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 28 );
	set( "weight", 280 );
	set( "value", ({ 1970, "silver" }) );
}
