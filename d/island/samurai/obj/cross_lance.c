
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "cross lance","十字枪" );
        add( "id",({ "lance","cross" }) );
        set_short( "cross lance","十字枪" );
        set_long(@AAA
这是一把巨大的十字枪,除非是个相当有力量的人,不然是用不起这种大兵器的
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 36 );
        set( "type", "thrusting" );
        set( "min_damage", 15 );
        set( "max_damage", 38 );
        set( "weight", 250 );
        set( "value", ({ 1230, "silver" }) );
}



