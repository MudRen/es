#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("����ҵ�");
	set_long( 
@LONG_DESCRIPTION
һ���������������յİ���������ҵ���Ķ��˵��л�����ͼ����
���﹩����ǻ������ڰ�����Ĵ�˵�л����ǻ��������֮һ��������ʱҲ
��ó����γ��֡��㿴��ǽ�ϵıڻ��������е�������̽���ߣ��Լ�����
������ʹӣ�����������������ֵ����ա�
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple10",
     ]) );
set ("objects", ([
     "r_enforcer":OMONSTER"r_enforcer",
     "wprayer":OMONSTER"wprayer"
     ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
