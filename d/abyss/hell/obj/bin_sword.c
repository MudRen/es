#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "blacksteel longsword", "长剑" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "a blacksteel longsword", "镔铁长剑" );
	set_long(
		"You see a blacksteel longsword.\n",
		"一把用坚硬的镔铁铸成的长剑。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 30 );
	set( "min_damage", 14 );
	set( "max_damage", 27 );
	set( "weight", 140 );
	set( "value", ({ 620, "silver" }) );
	set( "no_sale", 1 );
}
