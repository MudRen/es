#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ��ۣ���˵��
˵���������������ˣ�
LONG
             );
    set("exits",([
            "south":AREA"way1"]) );
    set("objects",([
            "lizard":TMOB"lizard"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
