#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ʹ����");
    set_long(@LONG
����һ����ȫ��ʯ���̳ɵĴ�����ɲ������жϣ�Ӧ����ȡ��������ɽ
�£����㲻����֪��������������ȡ�ģ����˶��������������ܽ������
�����Ŀ������
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"garden2",
        "west":CITY"pool",
        "south":CITY"gate5",
        "north":CITY"inway2"]) );
    reset();
#include <replace_room.h>
}