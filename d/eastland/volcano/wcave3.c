#include "oldcat.h"

inherit ROOM;

void create()
{
        ::create();
        set_short( "�ص���ͷ" );
        set_long(
@LONG
��վ�ڵص��ľ�ͷ��һ��С��������ͨȥ�����ػ��ɣ�������ǳ����ˡ�
LONG
        );
	set( "exits", ([
        "up" : ONEW"varea5"
	]) );
        set("objects", ([
            "oregon":OMONSTER"oregon",
            ]) );
        reset();
#include <replace_room.h>
}
