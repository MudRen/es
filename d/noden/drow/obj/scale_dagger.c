#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "snake scale dagger","绞鳞匕首");
        add( "id",({ "dagger" }) );
        set_short( "绞鳞匕首");
        set_long(
@C_LONG
这是把由八歧大蛇的蛇鳞所磨制的锋利匕首，刀刃的部份黝黑而没
有任何的光泽，是大蛇的鳞片所独有的特徵，刀柄并刻有蜘蛛图形
的文字。
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 22);
        set( "type", "dagger" );
        set( "min_damage", 16 );
        set( "max_damage", 24 );
        set( "weight", 50 );
        set( "bleeding", 10);
        set( "value", ({ 710, "silver" }) );
}
