#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ����ߺ�����
�˾�ס�����ӣ�
LONG
             );
    set("exits",([
            "east":AREA"house1",
            "southwest":AREA"way2",
            "north":AREA"way5"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
