#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
���������ǽ�������ħ��ƽ���ס��һ����䡣ħ�嶯������ǰ����
�Ѿ�ȷʵ���ö��й滮������һ�н��趼��ʹ���尲�����١����ҿ��ٷ�չ
��������еĽ��趼�Դ˹���Ϊǰ�������С�
LONG
             );
    set("light",1);
    set("exits",([
        "east":CITY"sway3"]) );
    set("objects",([
        "resident2" :TMOB"resident2" ]) );
    reset();
#include <replace_room.h>
}



