#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ���������ϣ�������ϱ߷������죬�������Ǳ����
���������ǳ����ĵ�·�������ҹ��嶼��ס����������߿ɴ����ſڡ�����
���������ݶ���ֵ����ƣ����深�������Զ���һ���ŵ����̡�
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nw1",
           "south" : SCITY"ww",
           "north" : SCITY"wn2",
        ]) );
	reset();
}
