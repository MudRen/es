#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu gloves", "天羽手套");
        add( "id", ({ "gloves" }) );
        set_short("tanyu gloves", "天羽手套");
        set_long(@AAA
这是天羽剑派特有的手套
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 3 );
        set( "defense_bonus", 3 );
        set("material","light_metal");
        set( "weight", 20 );
        set( "value", ({ 560, "silver" }) );
}
