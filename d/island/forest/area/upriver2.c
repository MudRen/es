#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����������С���Ͽ���ֻ����һ�ж���Ǭ�����ͷ�����Ĵ��������ż
���м�ֻС��֨֨���Ƶķɹ����ѵ��������ν�ġ�������Դ���������
���涼�Ǹ��ʵ�ɽ�ڣ����㲻����ǣ����������û�����˻����������ߵ�
ɳ���ϳ���һ�÷ǳ�ï�ܵĴ�����
LONG
            );
    set("exits",([
        "east":AREA"entrance2",
        "down":AREA"river2",
        "north":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

