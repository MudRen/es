#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����������С���Ͽ���ֻ����һ�ж���Ǭ�����ͷ�����Ĵ��������ż
���м�ֻС��֨֨���Ƶķɹ����ѵ��������ν�ġ�������Դ����
LONG
            );
    set("exits",([
        "east":AREA"entrance",
        "down":AREA"river",
        "north":AREA"upriver1",
        "south":AREA"upriver2"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

