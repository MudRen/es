
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "iron blade", "铁长刀" );
        add( "id",({ "sword","blade" }) );
        set_short( "iron blade", "铁长刀" );
        set_long(@AAA
这是一把普通士兵用的武器
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 10 );
        set( "type", "longblade" );
        set( "min_damage", 5 );
        set( "max_damage", 12 );
        set( "weight", 100 );
        set( "value", ({ 320, "silver" }) );
}



