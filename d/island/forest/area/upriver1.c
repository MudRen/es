#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ٲ�");
    set_long(@LONG
����������С���Ͽ���ֻ����һ�ж���Ǭ�����ͷ�����Ĵ��������ż
���м�ֻС��֨֨���Ƶķɹ����ѵ��������ν�ġ�������Դ���𣿱�����
�ߴ��ɽ�ڣ������и�ʮ��׳�۵��ٲ�������ͷ�����������γ�һ��������
�ʺ磻������һƬСɳ����
LONG
            );
    set("exits",([
        "east":AREA"entrance1",
        "down":AREA"river1",
        "south":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

