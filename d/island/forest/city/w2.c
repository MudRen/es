#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ҵ��·");
    set_long(@LONG
����һ������ʯ��Ĳ�ҵ�����Ҳ��ƽʱ�������ǡ����������Ψһ;
������������������������Էָ���·��ũ�������Ϊ����Ĳ�С�ļ�̤
�����˱����ũ��������ǡ���������ũ��������ڡ�
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"w3",
        "west":CITY"w1",
        "north":CITY"farm5"]) );
    reset();
#include <replace_room.h>
}
