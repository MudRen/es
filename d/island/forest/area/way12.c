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
            "southeast":AREA"way13",
            "northwest":AREA"gangway2"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
