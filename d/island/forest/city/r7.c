#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@LONG
���ǽ����������ģ�Ҳ��Ψһ����Ҫ��·�����������˴���������ʱ
������ţ���֦�Ѿ������Թ㷺�ķ�չ����������Ѿ��γ�һ����������
Ȼ����ˡ�
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "west":CITY"r6"]) );
    set("objects",([
          "woman" : TMOB"resident4"
                  ]) );
    reset();
#include <replace_room.h>
}
