#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "pallium", "僧袍" );
   set_short( "僧袍" );
	set_long(
		"这是一件很普通的和尚穿的青布僧袍。\n"
	);
	set( "unit", "领" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 1 );
	set( "defense_bonus", 3 );
	set( "weight", 50 );
	set( "value", ({ 270, "silver" }) );
}
