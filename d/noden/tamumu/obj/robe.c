#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ebony robe", "黑色法衣" );
	add( "id", ({ "robe" }) );
	set_short( "黑色法衣" );
	set_long(
	"这件黑色法衣又宽又厚重，如果你晚上穿上它，在黑暗中一定很难被发现。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 18 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "magic":3, "fire":-5 ]) );
	set( "weight", 100 );
	set( "value", ({ 740, "silver" }) );
}
