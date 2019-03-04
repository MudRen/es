#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("white cloth","白衣");
        add("id",({"cloth"}) );
         set_short( "White cloth","白衣");
	set_long(
"This is a white cloth . \n"
"这是一件白色的布衣\n"
	);
	set( "unit", "件" );
	set( "weight", 80 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 2 );
	set( "value", ({ 520, "silver" }) );
}
