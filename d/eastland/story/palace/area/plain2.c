#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ݵ��ϵ�С·");
	set_long( @LONG
����վ��һ������С·�ϣ�С·�򶫱߷������죬�������̲�����������һ
����ƽ̨���ݵ��ϸ�ɫ������������Ǯ��żһ��΢�紵��������ͬ�������컨�㣬
��ܰ���ԣ�������Ƣ���̻�Ⱦ��½�մ��һ��������
LONG
	);
	set("light",1);
        set( "exits", ([
            "plate" : SPALACE"plain1",
             "east" : SPALACE"plain3"
        ]) );
	reset();
}
