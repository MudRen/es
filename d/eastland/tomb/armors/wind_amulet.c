#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind amulet", "风之护符" );
	add( "id", ({ "amulet" }) );
	set_short( "风之护符" );
	set_long(
		"这是一张奇异的护符，闪耀著浅紫色的光芒，你可以感受到它充满了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "divine": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1100, "silver" }) );
}
