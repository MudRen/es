#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Light Sword","魔兽剑");
    add("id",({"sword"}) );
    set_short("魔兽剑");
    set_long(@LONG
这是魔兽所幻化而成的光剑，你能拥有这光芒耀眼的剑，表示你已经与这只魔兽
订了契约，今後将会听从你的命令。
LONG
            );
    set("unit","把");
    set("light",1);
    set("weapon_class",21);
    set("type","shortblade");
    set("min_damage",13);
    set("max_damage",26);
    set("weight",150);
    set("value",({650,"silver"}) );
}

