// eda5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���ﲨ���ǹ�������");
    set_long(@C_LONG
���������ﲨ���ǹ��ı��ᣬ����ɢ�����ٻ���ʯ������Ƭ������ħ��һ
�������˼�Ϊ���µ����ѣ��Ż������������ľ�����ط�Ӧ��Ҳ�ѻķ���
һ�κܳ���ʱ���ˡ�
C_LONG
    );
    set("exits", ([ "east" : AREA"eda4" ]) );
    reset();
}

