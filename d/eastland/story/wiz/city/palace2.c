#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ʹ�������");
	set_long( @LONG
�����������̳ǡ�����ľ�������ʹ����档�������Ը�վ�����������ӵ�
��ǰ�������Ǹ�����گ��������ġ�ǰ������׽������������飬ǰ�治Զ����
�����������Ա��������ĵط������������������Ѽ���
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "north" : SCITY"palace3",
              "out" : SCITY"palace1"
        ]) );
	reset();
}
