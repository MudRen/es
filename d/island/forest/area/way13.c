#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ������ǽ���
�����ţ�
LONG
             );
    set("exits",([
            "south":AREA"way14",
            "north":CITY"gate2",
            "northeast":AREA"way16",
            "northwest":AREA"way12"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
