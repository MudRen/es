#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("皇宫大道");
    set_long(@LONG
这是一条完全由石板铺成的大道，由材质来判断，应该是取自西方的山
崖，令你不禁想知道当年皇族是如何取材，花了多少人力物力才能建出如此
工整的宽广大道．
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"inhouse2",
        "west":CITY"inway2",
        "south":CITY"garden2",
        "north":CITY"garden3"]) );
    reset();
#include <replace_room.h>
}            
