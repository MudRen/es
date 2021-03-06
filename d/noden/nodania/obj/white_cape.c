#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white cape", "白披风" );
	add( "id", ({ "cape" }) );
	set_short(  "白色披风" );
	set_long(
		"这件白色披风看起来很漂亮而且昂贵，上面有一个小小的玫瑰标志。\n"
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material" ,"cloth" );
	set( "armor_class", 4 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "mental":3 ]) );
	set( "value", ({ 136, "gold" }) );
}
