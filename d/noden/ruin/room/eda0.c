// eda0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���з���");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣�Ϸ��Ķ�����
����������ĵط����������ԭ·��ȥ�ǲ�̫���ܵ��¡������������Ȼ����
��������˷����������˸��ܵ��̹ǵĺ��⡣
C_LONG
    );
    set("exits", ([ "north" : AREA"eda1" ]) );
    reset();
}


