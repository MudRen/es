#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ɽ��");
	set_long( 
@LONG_DESCRIPTION
��վ��ɽ������̧ͷ������ȥ����������Ҫ�����ɽ����һ��ξ��룬��Ϣһ��
�ɡ������������Ļ�ɽɽ���ƺ�����������Ũ��ð������֪��ʱ�����ٱ����������
����ǳ����ȣ���������������������������ȥ�����ﵽ�����ǻ�ɽ�Һ͸�ʯ������
�ɻ�ɽ�������ɵĻ�ɽ����춵����Ǿ޴���ѷ죬����뵽��ɽ�����൱���ѵġ�
LONG_DESCRIPTION
	);

set( "exits", ([
     "northeast" : ONEW"varea5",
     "north" : ONEW"varea3",
     "down" : ONEW"varea1" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
