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
        "east":CITY"inhouse2",
        "west":CITY"inway2",
        "south":CITY"garden2",
        "north":CITY"garden3"]) );
    reset();
#include <replace_room.h>
}            
