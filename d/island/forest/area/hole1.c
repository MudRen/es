#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����ں�խխ�ģ��ֳ����Ķ����˱ǵĳ�ɧζ���������˻��������
��ϸһ�����ƺ��ж���ĺ���������ʲ�ᶯ��ĳ�Ѩ��?
LONG
             );
    set("exits",([
            "out":AREA"way14",
            "south":AREA"hole2"]) );
    set("objects",([
            "s_wolf":TMOB"s_wolf"]) ); 
    reset();
#include <replace_room.h>
}

