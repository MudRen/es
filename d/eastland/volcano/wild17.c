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
�Ĳ������������������൱�ȣ�����������ȥ����Ȼ����һ���޴�Ļ�ɽ������
�Ƕ���
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"varea1",
     "southeast" : ONEW"wild20",
     "southwest" : ONEW"wild18",
     "south" : ONEW"wild16",
     "northwest" : ONEW"wild14",
     ]) );
set( "objects", ([
     "mrat":OMONSTER"mrat" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
