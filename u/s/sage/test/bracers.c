#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "dragon bracers", "神龙护腕" );
        add( "id", ({ "bracers" }) );
        set_short( "神龙护腕" );
        set_long(@C_LONG
这是杀手门的镇门之宝，相传它能够提升一个人的基本内功能力。
它看起来是由某种银丝做成的，上面绣著一条黑色的龙。
C_LONG
        );
        set( "unit", "双" );
        set( "type", "hands" );
        set( "no_sale", 1 );
        set( "armor_class", 1 );
        set( "extra_skills", (["inner-force":100]) );
        set("material","cloth");
        set( "weight", 1 );
        set( "value", ({ 10000000, "gold" }) );
}

