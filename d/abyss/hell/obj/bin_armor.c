#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blacksteel armor", "战甲" );
	add( "id", ({ "armor" }) );
	set_short( "a suit of blacksteel armor", "镔铁战甲" );
	set_long(
		"You see a suit of blacksteel armor.\n",
		"一套用坚硬的镔铁铸成的战甲。\n"
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "armor_class", 25 );
	set( "defense_bonus", 5 );
	set( "weight", 300 );
	set( "value", ({ 830, "silver" }) );
	set( "no_sale", 1 );
}
