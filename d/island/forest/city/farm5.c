#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����������ũ����");
    set_long(@LONG
�����ǡ���������ũ������������ȥ�������κε����������е��߲˶�����
һ��С����װ��������Ư���ڿ��У��Ϸ�Χ����һ��ħ���ڣ����Թ��˴����е�
���ʼ���ֹ�ȶ�ɢʧ�������������һ�в������߶ȵ���Ȥ��
LONG
            );
    set_outside("island");
    set("objects",(["farmer":TMOB"farmer"]) );
    set("exits",([
        "west":CITY"farm4",
        "south":CITY"w2"]) );
    reset();
#include <replace_room.h>
}
