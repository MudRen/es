#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silk tail", "黑丝绑尾" );
	add( "id", ({ "silk","tail" }) );
	set_short( "黑丝绑尾" );
	set_long(
"这是一副用黑蚕丝编成的护套，专门用来保护蜥蜴人的尾巴。\n"
	);
	set( "unit", "副" );
        set("material","cloth");
	set( "type", "tail" );
	set( "armor_class", 5 );
	set( "weight", 70 );
	set( "value", ({ 240, "silver" }) );
}
