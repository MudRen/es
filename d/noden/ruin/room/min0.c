// min0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@C_LONG
�����Ǹ�������ڣ�������������أ�����û��ׯ����ʥ�����գ�����
���˾�����Щ��ɭ�ֲ���������������￴ȥ������һƬ�ڰ������������Ҫ
�ҵ����ڵĻ���ֻ��Ӳ��ͷƤ��ǰ���ˡ�
C_LONG
    );
    set("exits", ([ "north" : AREA"min1" ]) );
    reset();
}


