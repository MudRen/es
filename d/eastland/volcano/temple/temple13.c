#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("�������");
	set_long( 
@LONG_DESCRIPTION
һ�����������ȣ���������ͨ����Ժ��������ͨ�������ң����Ͽ���ͨ�����
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OTEMP"temple23",
     "south" : OTEMP"temple11",
     "west" : OTEMP"temple22"
     ]) );
set("objects", ([
    "worker":OMONSTER"worker",
    ]) );
reset();
#include <../replace_room.h>
}
