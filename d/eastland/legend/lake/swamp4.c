#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("����");
        set_long( 
@LONG
������������⣬���߽�����Σ�յ�����أ����ܶ�����������������������
�µ����������Ƕ��㻢��������ʱ�����˹�����ҧ������ʺ�˺���������
����ʳ����Խ���������һ���ҽУ�ԭ����ʳ�����棡��Ż����ŵ����Ҹ��ط���
�ܣ�������������������ֵֹ����￿�˹���������������ֻ��һ���뷨�����ǡ�
����������
LONG
    );
    set( "exit_suppress", ({
            "east","south","west","north" }) );
                 
    set("exits",([
            "south":LAKE"swamp5",
            "east":LAKE"swamp2",
            "west":LAKE"swamp3",
           "north":LAKE"swamp2"
       ]) );
    set("objects",([
            "lizard#1":LMONSTER"lizard",
            "lizard#2":LMONSTER"lizard",
            "lizard#3":LMONSTER"lizard",
            "lizard#4":LMONSTER"lizard",
            "lizard#5":LMONSTER"lizard",
            ]) );
    reset();
}

