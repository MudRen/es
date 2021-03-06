#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder amulet", "雷之护符" );
	add( "id", ({ "amulet" }) );
	set_short( "雷之护符" );
	set_long(
		"这是一张奇异的护符，闪耀著青白色的光芒，你可以感受到它充满了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "electric":15, "mental": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1300, "silver" }) );
}
