#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("�������");
	set_long(
@LONG_DESCRIPTION
һ�����������ȣ��㿴��ǽ�������ڻ���������ɽ����ʱ�ľ��񣬻�ɽ������
���������еķ����������Ĵ����ܡ����Ͽ���ͨ�����������ͨ��������
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OTEMP"temple9",
     "north" : OTEMP"temple13",
     ]) );
reset();
#include <../replace_room.h>
}
