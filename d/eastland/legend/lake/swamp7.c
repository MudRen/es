#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
object toad;
        ::create();
    set_short("����");
        set_long( 
@LONG
������������⣬���߽�����Σ�յ�����أ����ܶ�����������������������
��ֵ��ǣ����ﲻ����������س�����ʽ�������˵ľ��͹��Ҳû������ġ���
���෴�ģ����ﵽ�����Ǿ���������޵Ĳк���Ī�����ྲ�������г���������һ
��Ũ���Ѫ�ȶ��֮�⣬����һ������ë���Ȼ���ľ������ĸо���һ���ƺ�����
�����ǻ��˵ĸо���
LONG
    );
    set( "exit_suppress", ({
        "east","south","west","north","southwest" }) );
    set("exits",([
            "east":LAKE"swamp6",
            "west":LAKE"swamp4", 
           "south":LAKE"swamp2",
           "north":LAKE"swamp5",
       "southwest":LAKE"swamp8",
       ]) );
       toad = new(LMONSTER"redtoad");
       toad->move(this_object());
        
       reset();
}
int clean_up()
{
       return 0;
}

