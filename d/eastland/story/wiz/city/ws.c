#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ���������ϣ���������߷������죬�ϱ������ϴ�֡�
�����������ⷢչ����֣�����������Ǩ�Ƶ���������һʱ�˳�ӿ�ڣ���������
�����;������������ݶ����֮�ϣ��ɴ������߿�ͨ�����ſڣ��������ֱ��Ǽ�
��������ҩ�ꡣ
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hospital1",
       	   "north" : SCITY"ww",
       	   "south" : SCITY"sw",
        ]) );
	reset();
}
