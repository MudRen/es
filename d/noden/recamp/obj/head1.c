#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold head","贵重头饰");
        add( "id", ({ "head" }) );
        set_short("Gold head", "贵重头饰");
        set_long(@AAA
这是一件用贵重金属打造而成的头带，提供严密的保护。
AAA
        );
        set( "unit", "件"); 
        set( "type", "head" );
        set( "armor_class", 10 );
        set("material","heavy_metal");
	set( "weight", 35 );
        set( "value", ({ 1000, "silver" }) );
}
