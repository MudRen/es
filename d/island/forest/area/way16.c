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
            "east":AREA"way18",
            "north":AREA"way15",
            "southwest":AREA"way13"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
