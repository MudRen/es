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
��ֵ��ǣ����ﲻ����������س�����ʽ�������˵ľ��͹��Ҳû������ġ���
���෴�ģ����ﵽ�����Ǿ���������޵Ĳк�����Ȼ���Ѿ�վ�������һ��ʱ�䣬
��ȴû���κ�һֻ����׷������������Ѱ���������ߵĿ�����������һ��Ũ���Ѫ
�ȶ������ɶ�����������̱ǣ������ţ�����ÿ��һ��ʱ��ʹ���һ���Х����
������ţ�裬��ȴԶ�������������룬һ���Ǹ��ֲ��Ĺ��
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south" }) );
    set("exits",([
            "east":LAKE"swamp5",
            "north":LAKE"swamp3",
            "west":LAKE"swamp7",
            "south":LAKE"swamp3"
       ]) );
    reset();
}

