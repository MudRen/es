#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed gauntlets", "合金护手" );
	add( "id", ({ "gauntlets" }) );
	set_short( "a pair of alloyed gauntlets", "合金护手" );
	set_long(
		"You see a pair of alloyed gauntlets. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"这是一双用某种不知名合金打造的护手，看起来相当重。\n"
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "heavy_metal");
	set( "armor_class", 5 );
	set( "weight", 80 );
	set( "value", ({ 760, "silver" }) );
}
