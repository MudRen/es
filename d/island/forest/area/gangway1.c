#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ɽ������");
    set_long(@LONG
����һ����խ��ͨ���������Ǹ��ʵ�ɽ�ڣ��ƺ���ʱ������ʯ������һ����
��ʱ���������Ĺֽ��������˲���������
LONG
            );
    set("exits",([
            "west":AREA"entrance",
            "east":AREA"gangway2"]) );
    set_outside("island");
     reset();
}
