#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ����ߵ�ɽ��
�ƺ��б��������ĺۼ���
LONG
             );
    set("exits",([
            "west":AREA"way15",
            "south":AREA"way18"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

