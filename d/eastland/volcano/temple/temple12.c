#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("�������");
	set_long(
@LONG_DESCRIPTION
һ�����������ȣ�һ��������񣬱����ǽ���ϣ���Щ����Ŀ������ˣ�������
���ص����գ����Ͽ���ͨ�����������ͨ����Ժ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OTEMP"temple10",
     "north" : OTEMP"temple14",
     ]) );
reset();
#include <../replace_room.h>
}
