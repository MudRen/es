#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ּ�С��");
    set_long(@LONG
û�뵽������ɽ��֮�⣬չ������ǰ�ľ���һƬ��������������ķ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ��ϱ��ǽ���
�Ǳ��ţ�
LONG
             );
    set("exits",([
            "west":AREA"way1",
            "south":CITY"gate3",
            "northeast":AREA"way4",
            "southeast":AREA"way15"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
