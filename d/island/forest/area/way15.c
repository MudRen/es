#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ�
LONG
             );
    set("exits",([
            "east":AREA"way17",
            "south":AREA"way16",
            "northwest":AREA"way2"]) );

    set_outside("island");
    reset();
#include <replace_room.h>
}
