
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "evil dragon dagger", "孽龙寒匕" );
        add( "id",({ "dagger","dragon" }) );
        set_short( "孽龙寒匕" );
        set_long(@C_LONG
这是以孽龙恨天之血浸润过的匕首，并将之浸泡在万年寒泉中数百年，
故其锋利无比，其上亦有闪烁著奇异的金属光芒。
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 23 );
        set( "max_damage", 36 );
        set( "weight", 50 );
        set( "value", ({ 400, "gold" }) );
}

