#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ҵ��·");
    set_long(@LONG
����һ������ʯ��Ĳ�ҵ�����Ҳ��ƽʱ�������ǡ����������Ψһ;
������������������������Էָ���·��ũ�������Ϊ����Ĳ�С�ļ�̤
�����˱����ũ���
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"w2",
        "west":AREA"gangway2"]) );
    reset();
#include <replace_room.h>
}
