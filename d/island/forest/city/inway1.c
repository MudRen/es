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
        "east":CITY"inway2",
        "west":CITY"gate4",
        "south":CITY"pool",
        "north":CITY"garden1"]) );
    reset();
#include <replace_room.h>    
}