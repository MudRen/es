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
����ʳ����Խ���������һ���ҽУ�ԭ����һֻ��Ѫ������ݺݵ�ҧס��Ĳ��ӣ�
��Ż����ŵ��õ��������������������������������ֵֹ����￿�˹���������
������ֻ��һ���뷨�����ǡ�����������
LONG
    );
    set( "exit_suppress", ({
            "north","east","west","south" }) );
    set("exits",([
            "north":LAKE"swamp2",
            "west":LAKE"swamp5",
            "east":LAKE"swamp3",
           "south":LAKE"swamp2"
        ]) );
    set("objects",([
          "leech#1":LMONSTER"leech",
          "leech#2":LMONSTER"leech",
          "leech#3":LMONSTER"leech"         
         ]) );
    reset();    
}

