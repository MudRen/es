#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�յ�");
	set_long( 
@LONG_DESCRIPTION
��Ƭ�յ���᫲�ƽ�������м����޴���ѷ죬�����յ�Ū�ɿ������ķ����ѵģ�
�������Ǻں�ɫ��ʯͷ����ɫ��������ʹ��һ��������͵����֪��һ���ǻ�ɽ������
�Ĳ������������������൱�ȣ��򱱷���ȥ����Ȼ����һ���޴�Ļ�ɽ��������
����
LONG_DESCRIPTION
	);
set( "exits", ([
     "north" : ONEW"varea1",
     "northwest" : ONEW"wild17" ]) );
set( "objects", ([
     "whunter":OMONSTER"whunter" ]) );
set_outside("eastland");
reset();
}
