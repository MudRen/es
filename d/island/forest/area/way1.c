#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ּ�С��");
    set_long(@LONG
û�뵽������ɽ��֮�⣬չ������ǰ�ľ���һƬ��������������ķ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ�
LONG
             );
    set("exits",([
            "southwest":AREA"gangway2",
            "east":AREA"way2",
            "north":AREA"way3"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
