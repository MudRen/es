#include "oldcat.h"

inherit ROOM;

void create()
{
::create();
set_short("����");
set_long( 
@LONG_DESCRIPTION
��վ��һƬ��ɫ���ֵ�С���У���Ƭ�������ٵ����֣�ʹ���������ڴ���Ȼ��
�о�������ï�ܵ�����֮�У��㻹������������������Щ����һ��֪����������
����������С����֪����ͨ��δ���
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest": "/d/eastland/5,1.east",
     "east" : ONEW"wild2", ]) );
set( "objects", ([
     "ohio":OMONSTER"ohio" 
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
