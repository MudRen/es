#include "../island.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��ƽ������");
	set_long(@C_LONG
������Ǻ�ƽ�����õ�һ¥���м�������ʯ�����������ġ�ͣս����
���������������״�е�����һ�ѳ�������������������������������
��ֹ춴˵ء�����¥�ǹ������ģ�����ʷ�������ҡ�
C_LONG
		);
	set("light",1);
	set("exits",([
                 "east" : ITOWN"square07",
                 "west" : ITOWN"square03",
               "south"  : ITOWN"square05",
               "north"  : ITOWN"square01",
                 "up"   : ITOWN"museum01"
            ]) );
        set("objects",([
                 "stone":IOBJ"stone"
                 ]));      
	reset();
}
