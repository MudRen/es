#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�յ�");
	set_long( 
@LONG_DESCRIPTION
��Ƭ�յ���᫲�ƽ���������Ǻ�ɫ��ʯͷ�����ɫ����������һ���������
�����֪��һ���ǻ�ɽ������Ĳ����������Ҳ�����������ȵģ����һ����
��ɽ���⸽���������ǰ�����Ĳ���ض������ﲻ�Ǻ�Զ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"wild17" ]) );
set( "objects", ([
     "deadman":OMONSTER"deadman" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
