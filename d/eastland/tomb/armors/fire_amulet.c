#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire amulet", "火之护符" );
	add( "id", ({ "amulet" }) );
	set_short( "火之护符" );
	set_long(
		"这是一张奇异的护符，闪耀著亮红色的光芒，你可以感受到它充满了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "fire":15, "cold": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1400, "silver" }) );
}
