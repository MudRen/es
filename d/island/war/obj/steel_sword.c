#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel sword", "精钢长剑" );
        add( "id",({ "sword" }) );
        set_short( "steel sword", "精钢长剑" );
        set_long(@AAA
这是以把锋利的长剑，是用特殊钢材做成的，是武士团边境守备队的制式武器
AAA
);
        set( "unit", "把");
        set( "weapon_class", 30 );
//        set( "bleeding", 5 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 28 );
        set( "weight", 170 );
        set( "value", ({ 720, "silver" }) );
}



