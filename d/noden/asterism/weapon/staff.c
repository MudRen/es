
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "magic staff", "法杖");
        add ("id",({ "staff" }) );
        set_short( "法杖");
        set_long(
            "这是地精族所使用的武器，它并不锋利而且没有魔法的特殊攻击，\n"
            "但是他的特殊材质使得其攻击力有一定强度。 \n" );
        set( "weapon_class", 25 );
        set( "min_damage", 14);
        set( "unit","把");
        set( "max_damage", 20);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

