#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@LONG
���ǽ����������ģ�Ҳ��Ψһ����Ҫ��·�����������˴���������ʱ
������ţ���֦�Ѿ������Թ㷺�ķ�չ����������Ѿ��γ�һ����������
Ȼ����ˡ�
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"gate4",
        "south":CITY"r4",
        "north":CITY"gate3"]) );
    reset();
#include <replace_room.h>
}