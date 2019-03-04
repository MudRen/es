#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black robe", "捕快服" );
	add( "id", ({ "robe" }) );
	set_short( "an black robe", "捕快服" );
	set_long(
		"You see a pliceman's black robe.\n",
		"这是一件古梅镇捕快专用的制服。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
        set("material","cloth");
	set( "weight", 80 );
	set( "armor_class", 15 );
	set( "value", ({ 150, "silver" }) );
}
