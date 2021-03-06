#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『迷雾森林』入口");
    set_long(@LONG
山崖的下方竟有一条通道，通道的尽头似乎是一大片的森林，那儿想必
就是冒险者口中的『迷雾森林』了吧！多年以来，有很多的冒险者对这森林
的一切非常感兴趣。魔族的一支在此建国後，便依赖此地的隐密性努力的发
展，不知道目前的森林变的如何了呢！旁边壁上似乎有些刻字(words)。
LONG
    );
     set("c_item_desc",([
      "words":@LONG
　　　　　　　『此处乃是魔族国境，目前正值戒严时期，
　　　　　　　　过往旅客请熟记密码，以确保国家安全！』
LONG
                      ]) );
    set_outside("island");
    set("exits",([
            "north":AREA"entrance1",
            "east":AREA"gangway2",
            "west":AREA"upriver",
            "south":AREA"entrance2"]) );
     reset();
#include <replace_room.h>
}
