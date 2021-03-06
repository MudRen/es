#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("征木神社");
    set_long(@LONG
神社中似乎没有想像中的那麽可怕，只见简单的陈设，供奉著三位守护灵：
一位是『船穗』，一位是『龙皇』，另一位是『津名魅』；虽然这里并没有供奉
三位守护灵的雕像，无法得知他们的真面目，但是，传说他们都是很亲切和蔼的
灵，如果你有幸，说不定能见到他们显灵呢！外面那一棵就是『津名魅』！如果
你是有缘人，肯诚心诚意的在她面前祈祷(pray)，或许她会出现在你的面前哦！
LONG
            );
    set("light",1);
    set("exits",([
        "out":CITY"abbey"]) );
    set("no_monster",1);
    reset();
#include <replace_room.h>
}
