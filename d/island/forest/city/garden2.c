#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���ƺ");
    set_long(@LONG
����ǻʹ���Ψһ�Ĵ��ƺ��ƽʱ�����С���Ӿ��������Ϸ���棬ң
�����ż��Ҳ������ʹ������ֹ��£���������Ҫ����;����������ϰ��
�ĳ�����
LONG
             );
    set_outside("island");
    set("exits",([
        "west":CITY"inway4",
        "north":CITY"inway3"]) );
    set("light",1);
    set("objects",([
        "oldman":TMOB"leaderii",
        "prince":TMOB"tanki"]) );
    reset();
#include <replace_room.h>
}

