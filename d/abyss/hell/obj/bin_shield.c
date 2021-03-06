#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blacksteel large shield", "大盾" );
	add( "id", ({ "large shield", "shield", "blacksteel shield" }) );
	set_short( "a blacksteel large shield", "镔铁大盾" );
	set_long(
		"You see a blacksteel large shield.\n",
		"一面用坚硬的镔铁铸成的大盾。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "armor_class", 8 );
	set( "defense_bonus", 2 );
	set( "weight", 160 );
	set( "value", ({ 690, "silver" }) );
	set( "no_sale", 1 );
}
