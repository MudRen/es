#include "../forest.h"

inherit WEAPON;

void create()
{
        set_name( "sharp blade", "大刀" );
        add( "id",({ "blade", "sharp blade" }) );
        set_short( "锋利的大刀" );
        set_long( @CLONG
这是一把相当锋利的大刀, 白晃晃的锐利刀锋, 令人感受到一种一出
鞘就想见血的霸气。
CLONG
        );
        set( "unit", "把");
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "nosecond",1);
        set( "weight", 141 );
        set( "value", ({ 350, "silver" }) );
}
