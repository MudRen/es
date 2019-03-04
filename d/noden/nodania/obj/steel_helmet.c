#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel helmet", "钢头盔" );
	add( "id", ({ "helmet" }) );
	set_short( "钢头盔" );
	set_long(
		"这是一个钢制的头盔，上面还有保护脸部的铁面罩。\n"
	);
	set( "unit", "个" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 60 );
	set( "value", ({ 1520, "silver" }) );
}
