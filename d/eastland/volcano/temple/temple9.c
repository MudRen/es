#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("�������");
	set_long( 
@LONG_DESCRIPTION
һ�����������ȣ��㿴��ǽ�������ڻ����ǰ����������ʱ�����˺���������
�׼����˵����Σ����Χ���㳡�е�Ӫ���黶�֣�����������ߣ�����һ������
�Ĵ򣬻��������ģ��������ˡ����Ͽ���ͨ������������Ե���������ͨ
��������
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : OTEMP"temple5",
     "west" : OTEMP"temple17",
     "north" : OTEMP"temple11",
     ]) );
reset();
#include <../replace_room.h>
}
