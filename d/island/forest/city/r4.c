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
        "east":CITY"r6",
        "west":CITY"gate1",
        "south":CITY"gate2",
        "north":CITY"r2"]) );
    set("objects",([
        "police":TMOB"police"]) );
    reset();
#include <replace_room.h>
}
