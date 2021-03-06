#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("buddha hood", "麻罗□字顶巾");
        add( "id", ({ "hood" }) );
        set_short( "buddha hood", "麻罗□字顶巾");
        set_long(
                "A hood with a buddha mark .\n",
                "这是一顶麻纱巾，上有一个红色的□字，据说可以压制体内疯狂的 \n"
                "兽性．所以宋江特地将它赏给李逵．\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":7,"mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 300, "gold" }) );
}


