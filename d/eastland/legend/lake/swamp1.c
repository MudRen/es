#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp.c";

void create()
{
        ::create();
        set_short("����");
        set_long( 
@LONG
��������һ����Ţ�������У�����ĳ�ζ���ཬ���ª��ֲ�������̲�סһ��
������ش�һֱ�������̣�������һ��ķ�������Ҳ�������㼣��������վ�ĵ�
����ֻ������ı߽磬���㻹û�����������֮ǰ���뿪�ɡ�
LONG
    );
    set( "exit_suppress", ({
         "east","south","west" }) );
    set("exits",([
            "east":LAKE"swamp0",
            "south":LAKE"swamp2",
            "west":LAKE"swamp1"
       ]) );
    set("objects",([
          "mosquito#1":LMONSTER"mosquito",
          "mosquito#2":LMONSTER"mosquito"
         ]) ); 
    reset();
}

