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
����ʳ����Խ���������һ���ҽУ�ԭ����һֻ�Ⱥ�ɫ��������ݺݵ�ҧס�����
�ţ���Ż����ŵ����������߿���������������������ֵֹ����￿�˹���������
������ֻ��һ���뷨�����ǡ�����������
LONG
    );
    set( "exit_suppress", ({
         "north","south","west","east" }) );
    set("exits",([
            "south":LAKE"swamp3",
            "north":LAKE"swamp1",
             "east":LAKE"swamp2",  
            "west":LAKE"swamp4"
       ]) );
    set("objects",([
         "centipede#1":LMONSTER"centipede",
         "centipede#2":LMONSTER"centipede"
         ]) ); 
    reset();
}

