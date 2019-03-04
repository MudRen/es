#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "bloody claws", "血爪" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "血爪" );
        set_long(@C_LONG
这是一双百□精钢制成的钢爪，与一般铁爪不同的是它只有两片爪刃，
可是泛著血红色光芒的爪身却更长，简直跟两把短剑没什麽不同。
C_LONG
        );
        set( "unit", "双" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 2970, "silver" }) );
        set_c_verbs( ({ "用%s往%s一划", "%s划出一道血红色的闪光，扫过%s",
                "的%s「嘶」的一声，往%s划去", }) );
}
