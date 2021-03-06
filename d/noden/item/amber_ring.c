#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "amber ring", "琥珀戒指" );
	add( "id", ({ "ring" }) );
   set_short( "琥珀戒指" );
	set_long(
		"一个相当美丽的琥珀戒指，你感觉到它散发著一股魔力。\n"
	);
	set( "unit", "个" );
	set( "type", "finger" );
	set( "material", "element");
	set( "armor_class", 0 );
	set( "defense_bonus", 5 );
    set( "special_defense",
               ([ "mental":3, "electric":-3, "acid":3 ]) );
	set( "weight", 8 );
	set( "value", ({ 640, "silver" }) );
}
