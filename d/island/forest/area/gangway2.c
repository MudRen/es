#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ɽ������");
    set_long(@LONG
����һ����խ��ͨ���������Ǹ��ʵ�ɽ�ڣ��ƺ���ʱ������ʯ������һ����
��ʱ���������Ĺֽ��������˲��������������ƺ������ǣ�
LONG
            );
    set("exits",([
            "east":CITY"w1",
            "west":AREA"entrance",
            "northeast":AREA"way1",
            "southeast":AREA"way12"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
