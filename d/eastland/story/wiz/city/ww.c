#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ���������ϣ�����������Ϸ������죬���������ſڡ�
�����������ⷢչ����֣�����������Ǩ�Ƶ���������һʱ�˳�ӿ�ڣ���������
�����;�����Խ���һ���ŵ����ӡ��������ֱ��ǳ��������ùݣ����ṩ��Ϣ��
��
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hotel1",
       	    "west" : SCITY"westgate",
       	   "north" : SCITY"wn1",
       	   "south" : SCITY"ws",
        ]) );
	reset();
}
