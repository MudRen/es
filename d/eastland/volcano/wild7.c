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
����Χ���ˡ�
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : ONEW"wild2",
     "southeast" : ONEW"wild9",
     "northeast" : ONEW"wild8", ]) );
set( "objects", ([
     "adventurer#1":OMONSTER"adventurer",
     "adventurer#2":OMONSTER"adventurer",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
