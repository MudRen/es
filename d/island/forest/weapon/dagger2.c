#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name(" Prick","破魔锥");
    add("id",({ "dagger" }) );
    set_short("破魔锥");
    set_long( @C_LONG
这是魔族魔导士专用的武器，轻巧的设计使他成为战争中的利器。
C_LONG
            );
    set("unit","把");
    set("weapon_class",17);
    set("type","dagger");
    set("min_damage",10);
    set("max_damage",19);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
