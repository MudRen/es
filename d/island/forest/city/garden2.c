#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大草坪");
    set_long(@LONG
这而是皇宫内唯一的大草坪，平时王族的小孩子就在这儿嬉戏游玩，遥
照天皇偶而也会这儿和大臣们商讨国事；不过最主要的用途是拿来当作习武
的场所。
LONG
             );
    set_outside("island");
    set("exits",([
        "west":CITY"inway4",
        "north":CITY"inway3"]) );
    set("light",1);
    set("objects",([
        "oldman":TMOB"leaderii",
        "prince":TMOB"tanki"]) );
    reset();
#include <replace_room.h>
}

