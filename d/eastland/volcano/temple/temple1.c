#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("���������");
	set_long(
@LONG_DESCRIPTION
һ���������������յİ��������������������Ķ��˵��л����ͼ����
�ĸ��������Ƶľ޴����������ĸ����䣬ǰ���ƺ���һЩ�����Ƕ�������̫Զ��
�㿴�������������ʲ�ᣬҲ��֪����������ʲ����
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple4",
     "east": OTEMP"temple3",
     "west": OTEMP"temple2",
     "out" : OGROUP"warea16",
     ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
