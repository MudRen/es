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
            "south":AREA"hole3",
            "north":AREA"hole1"]) );
    set("objects",([
         "s_wolf#2":TMOB"s_wolf",
         "s_wolf#1":TMOB"s_wolf"]) );    
    reset();
#include <replace_room.h>
}
