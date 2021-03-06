#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "lucky amulet", "幸运护身符" );
	add( "id", ({ "幸运护身符", "amulet" }) );
	set_short( "幸运护身符" );
	set_long(
		"这是个黄金打造的护身符，上面刻满了各种\n"
		"代表平安、幸运的咒文。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
	set( "extra_stats",([ "kar" : 2 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
