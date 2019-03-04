#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "purple kernel", "紫晶核" );
    add( "id", ({ "kernel", }) );
    set_short( "紫晶核" );
    set_long(@LONG 
    一颗奇特的晶石，散出深遂美丽的紫色光芒，并从你手上接触的地方传来一股
源源不绝的能量，不知道有什麽特殊作用。     
LONG      );
    set( "unit", "颗" );
    set( "type", "kernel" );
    set( "material", "element" );
    set( "defense_bonus", 5 );
    set( "weight", 60 );
    set( "value", ({ 3, "silver" }) );
}
