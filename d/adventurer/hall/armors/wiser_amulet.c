#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "护身符" );
	add( "id", ({ "智者护身符" }) );
	set_short( "a wiser amulet", "智者护身符" );
	set_long(
		"This is Yamor's wiser amulet. You can see many symbols\n"
		"of fortune on it.\n",
		"这个护身符一向是亚默长老最常带在身边的，上面画满了各种\n"
		"代表平安、幸运的咒文。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
    set( "extra_status", ([ "int" : 1 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
