#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("�������");
	set_long( 
@LONG_DESCRIPTION
һ�����������ȣ����Ͽ���ͨ�����������ͨ������ң�������ͨ����Ժ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OTEMP"temple21",
     "south" : OTEMP"temple12",
     "west" : OTEMP"temple24"
     ]) );
set("objects", ([
    "worker":OMONSTER"worker",
    ]) );
reset();
#include <../replace_room.h>
}
