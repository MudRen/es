#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڶ�����ϣ���������߷������죬��������ƥ����
�Ŀ�ȣ��ϱ������ϴ�֡�����ֵĵ����ô���ʯ�̳ɵģ�����ĺ�Ǭ�����Դ���
���������ᣬ����ֱ���˳��������ֵĵط���ԭ����������Ϊ�����Ҫ������
��������������ϡ��������Զ���һ���ŵ��̵꣬��������һ�ҿ�˵�ǳ�������
һ���̵ꡣ
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	   "south" : SCITY"se",
       	   "north" : SCITY"ee",
            "west" : SCITY"store",
        ]) );
        set( "objects", ([
                "soothsayer":SWMOB"soothsayer1",
        ]) );
        reset();
}
