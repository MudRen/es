
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("??","���˵���Ӥ��");
    set_long(@Long
Long
,@CLong
һ�䰫�˵���Ӥ��,������Ĵ󲿷ֵ������ɴ˲���.
CLong
    );
    set("exits",([
                "south":Deathland"/village/v45",
             ]));
    set("objects",([
        "nurse#1":Monster"/nurse",
        "nurse#2":Monster"/nurse",
        "baby#1" :Monster"/baby",
        "baby#2" :Monster"/baby",
        "baby#3" :Monster"/baby",
        "baby#4" :Monster"/baby",
          ]) );
    ::reset();
#include <../replace_room.h>
}
