// rose0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("����");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣�����ƺ�����
С��ͨ���������㲻��������֣�����������ĵط��������������ĵ���֮
�⻹��˭�����أ�
C_LONG
    );
    set("exits", (["north" : AREA"rose1"]) );

    reset();
}
