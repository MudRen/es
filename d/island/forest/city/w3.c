#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ҵ��·");
    set_long(@LONG
����һ������ʯ��Ĳ�ҵ�����Ҳ��ƽʱ�������ǡ����������Ψһ;��
����������������������Էָ���·��ũ�������Ϊ����Ĳ�С�ļ�̤����
���˱����ũ����ϱ��ǡ�������������������ڣ������ǽ��������š�
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"gate1",
        "west":CITY"w2",
        "south":CITY"pasture3"]) );
    reset();
#include <replace_room.h>
}
