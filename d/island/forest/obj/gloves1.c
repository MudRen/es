#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Snow Gloves","雪护手");
    add("id",({"gloves"}) );
    set_short("雪护手");
    set_long(@C_LONG
雪神兽白虎的皮毛所制成的护手，可以造成冷气障碍壁垒。
C_LONG
    );

    set("unit","双");
    set("type","hands");
    set("material","light_metal");
    set("weight",30);
    set("armor_class",4);
    set("defense_bonus",1);
    set("value",({500,"silver"}) );
}
