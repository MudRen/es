#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�յ�");
	set_long(
@LONG_DESCRIPTION
��Ƭ�յ���᫲�ƽ���������Ǻ졢��ɫ��ʯͷ���Լ����ɫ����������һ�������
�͵����֪��һ���ǻ�ɽ������Ĳ����������Ҳ�����������ȵģ����һ���л�ɽ
���⸽����Զ���ƺ����������������������ͷ��Ĳ���һ��Ҳ�������ﲻԶ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : ONEW"wild17",
     "southwest" : ONEW"wild11" ]) );
set( "objects", ([
     "adventurer":OMONSTER"adventurer" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
