#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����");
        set_long( 
@LONG
�㷢����;�ϵ��续�����ƺ�ֻ������Ϊֹ��������ȥ��ֻ����ؿ�ľ������
�뵡���ǰ��һ�Ÿ�ʾ����һ��ľ���ϣ���ʾд����

                Σ�գ�����ͨ������ش����������С��綾��������
           ���С�������������Ұ�ޣ��밮ϧ��������ǧ����Բ�Ҫ���롻��

LONG
    );
    set("exits",([
            "northeast":LAKE"village1",
            "west":LAKE"swamp1",
       ]) );
    set("objects",([
             "crab#1":LMONSTER"crab",
             "crab#2":LMONSTER"crab",
             "crab#3":LMONSTER"crab",
             "crab#4":LMONSTER"crab",
             "crab#5":LMONSTER"crab"
    ]) );
    reset();
}

