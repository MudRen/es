#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@LONG
���ǽ����������ģ�Ҳ��Ψһ����Ҫ��·�����������˴���������ʱ
������ţ���֦�Ѿ������Թ㷺�ķ�չ����������Ѿ��γ�һ����������
Ȼ����ˡ��ϱ���һ��ƽ���ס�ĳ�����
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"r7",
        "west":CITY"r4",
        "south":CITY"sway1",
        "north":CITY"gate5"]) );
    reset();
#include <replace_room.h>
}
