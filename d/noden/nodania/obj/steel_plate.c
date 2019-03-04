#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel platemail", "钢盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "钢盔甲" );
	set_long(
		"这是一套钢制的沈重盔甲，不过它虽然重，却能提供相当好的防御力。\n"
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "weight", 320 );
	set( "value", ({ 2500, "silver" }) );
}
