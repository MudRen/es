#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ص׶�Ѩ");
    set_long(@LONG
�˵�һ������ײ���˶�Ѩ�Ķ�������������Ūʹ�ĵط�˳�㻷����һ�����ܣ�ֻ
��ǰ��һ���ãã����������������һ��һ�ŵĴ�ʯͷ���泤������ɫ����̦��Խ��
�Ͱ��Ŀռ�ʹ�����ǰ��Ӧ��û��ͨ·�ˡ�
LONG
    );
    set("exits",([
            "north":LAKE"swamp_d1"
    ]) );
    set("objects",([
        "beholder":LMONSTER"beholder1"
    ]) );    
    ::reset();
}

