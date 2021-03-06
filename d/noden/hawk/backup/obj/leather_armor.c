#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather armor", "皮甲" );
	add( "id", ({ "armor" }) );
	set_short( "皮甲" );
	set_long(
		"这件皮甲是用水牛皮做成的，闻起来还带有一股皮革所特有的臭味。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 14 );
    set( "special_defense",
         ([ "cold":2, "fire":-4, "electric":1 ]) );
	set( "weight", 100 );
	set( "value", ({ 210, "silver" }) );
}
