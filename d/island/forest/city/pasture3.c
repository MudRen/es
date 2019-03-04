#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『咖哩咖哩牧场』");
    set_long(@LONG
这里是『咖哩咖哩牧场』，也是魔族及半人马族乳品食物的主要供应场
所；在这里工作的主要都是半人马工人，畜养的大多是经过精选的优良牛只
，在魔族不断的改进畜养技术，及半人马们细心的照顾之下，每天都能生产
大量的鲜乳以供饮用和加工。
LONG
            );
    set_outside("island");
    set("exits",([
        "south":CITY"pasture6",
        "north":CITY"w3"]) );
    reset();
#include <replace_room.h>
}
