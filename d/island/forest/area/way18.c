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
            "west":AREA"way16",
            "north":AREA"way17"]) );
    set_outside("island");
    set("objects",([
         "hawk":TMOB"hawk"]) );
    reset();
#include <replace_room.h>
}

