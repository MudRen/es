#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("ʯ��");
	set_long( 
@LONG_DESCRIPTION
������һ���������ʯ���У����ﵽ���ǲйǶϺ���Ѫ���߰ߣ�����������������
���˾ͽ����ľ�������
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OGROUP"tunnel1",
     ]) );
set( "objects", ([
     "shuang":OMONSTER"shuang",
     ]) );
reset();
}
