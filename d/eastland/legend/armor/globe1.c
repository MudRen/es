#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "occult globe", "青灵护盾圆球" );
    add( "id", ({ "globe", }) );
    set_short( "青灵护盾圆球" );
    set_long(@LONG 
    一个球状的反物质,像是一种护盾产生器。
LONG      );
    set( "unit", "种" );
    set( "type", "globe" );
    set( "material", "element" );
    set( "defense_bonus", 10 );
    set( "weight", 100 );
    set( "value", ({ 200, "silver" }) );
}
