#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��ľ��");
	set_long( 
@LONG_DESCRIPTION
��վ����Ƭ��ľ���е�С���ϣ���ľ�ĸ߶ȴ�Լ�������߲�࣬����ĳ�
ʶ�жϣ��������������ˮ��Դ����������ḻ������С����û����β��Ĺ�
ľ��֮�У��㷢�������Աߵĵ�����һ̲Ѫ���ż������������Ѿ�����ͷ�����
����Χ���ˣ��㻹������һֻС���Ӷ��ڹ�ľ���￴���㡣
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "east" : ONEW"wild10",
     "northwest" : ONEW"wild7",
     "southwest" : ONEW"wild4", ]) );
set( "objects", ([
     "whunter":OMONSTER"whunter",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
