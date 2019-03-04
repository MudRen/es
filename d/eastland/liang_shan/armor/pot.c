#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Steel Pot", "不沾锅" );
	add( "id", ({ "pot" }) );
	set_short( "a pot", "不沾锅" );
	set_long(
		"??\n",
		"这面锅是用某种你从没见过的奇特金属制成的\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 150 );
	set( "value", ({ 500, "silver" }) );
}
