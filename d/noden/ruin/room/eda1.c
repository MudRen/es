// eda1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���з���");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣�����Ĳ�Զ��
�ƺ������⣬�ƺ������˾�ס�����ӣ�˵�����г����أ������������Ȼ����
��������˷����������˸��ܵ��̹ǵĺ��⡣
C_LONG
    );
    set("exits", ([ "north" : AREA"eda2" ]) );
    reset();
}

