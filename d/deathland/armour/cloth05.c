#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("beautiful cloth","漂亮的衣服");
        add("id",({"cloth"}) );
         set_short( "a beautiful cloth","漂亮的衣服");
	set_long(
"This is a a beautiful cloth.\n"
"这是一件漂亮的衣服\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 18 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "divine":3, "fire":-5 ]) );
	set( "value", ({ 1420, "silver" }) );
}
