#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
����ں�խխ�ģ��ֳ����Ķ����˱ǵĳ�ɧζ���������˻��������
��ϸһ�����ƺ��ж���ĺ���������ʲ�ᶯ��ĳ�Ѩ���ۡ�������ԭ����
ħ�ǵ���!!
LONG
             );
    set("exits",([
            "north":AREA"hole2"]) );
    set("objects",([
         "wolf":TMOB"wolf"]) );
    reset();
#include <replace_room.h>
}
