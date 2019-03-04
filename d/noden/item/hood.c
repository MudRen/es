#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "colorful hood", "花布头巾" );
	add( "id", ({ "hood" }) );
   set_short( "花布头巾" );
	set_long(
		"这条花布头巾已经很破旧了，戴著它看起来一定很土。\n"
	);
	set( "unit", "条" );
	set( "type", "head" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 24, "silver" }) );
}
