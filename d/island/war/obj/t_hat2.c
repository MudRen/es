#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Cap","战斗冠");
    add("id",({"hat","cap"}) );
    set_short("战斗冠");
    set_long(@LONG
这是一件轻巧精致的帽子。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",5);
    set("defense_bonus",2);
    set("weight",100);
    set("value",({300,"silver"}) );
}
