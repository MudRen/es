#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ʯ���");
    set_long(@LONG
����һ��ƽ̹���Ĵ�ֵ���ħ��������ñ�����֪�İ���ħ��������
�����������������������·����Ϊƽ̹�����������˸�ʽ�������е�����
���ڸ�·���㣬���̲�ס��Ҫפ���������ҡҷ����Ӱ�������Լ����ŵ���
��õ�Щ΢�ķ��ɡ�
LONG
           );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"school01",
        "west":CITY"hill2",
        "south":CITY"sway3",
        "north":CITY"sway1"]) );
    reset();
#include <replace_room.h>
}