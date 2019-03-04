#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "worn hat", "旧帽子" );
	add( "id", ({ "hat" }) );
   set_short( "旧帽子" );
	set_long(
		"这顶帽子已经很破旧了，上面有好几个破洞。\n"
	);
	set( "unit", "顶" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 15, "silver" }) );
}
