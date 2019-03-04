
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven staff", "精灵杖");
        add ("id",({ "staff" }) );
        set_short( "精灵杖" );
        set_long(
            "这是精灵长老所使用的武器，虽然它并不锋利而且没有魔法的特殊攻击\n"
            "但由於是采集五金的精华，加以淬冶而成的武器，故坚硬异常是不错的\n"
            "攻击武器。 \n" );
        set( "weapon_class", 20 );
        set( "min_damage", 10);
        set( "unit","把");
        set( "max_damage", 18);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

