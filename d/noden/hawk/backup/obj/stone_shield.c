#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "flinty shield", "隧石盾" );
	add( "id", ({ "shield" }) );
	set_short( "隧石盾" );
	set_long(
		"这是一面用暗红色岩石做成的盾，它看起来很重。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "stone");
	set( "armor_class", 5 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "fire":3, "electric":-2 ]) );
	set( "weight", 190 );
	set( "value", ({ 570, "silver" }) );
}
