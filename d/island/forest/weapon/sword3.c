#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Koku Sword","黑王剑");
    add("id",({"koku","sword"}) );
    set_short("黑王剑");
    set_long(@C_LONG
是传说中魔人黑王的剑，他会吸食失败者的血，所以早已化为
半妖剑。
C_LONG
    );

    set("unit","柄");
    set("weight",150);
    set("type","longblade");
    set("weapon_class",25);
    set("min_damage",12);
    set("max_damage",26);
    set("value",({600,"silver"}) );
}
