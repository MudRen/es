#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "�������" );
	set_long(
@LONG_DESCRIPTION
���Ǿ������Ĵ���Ȼ��������һ�������ڣ��������½�ϻʵ۵Ĺ���
��֪������ǧ�����ĳ��佫�������ԣ���������һ����ֵ��������㣬��
ǰ��ȥ���ƺ����˸߸ߵ��������档
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"palace1",
	     "north" : OTEMP"palace3",
	]) );
        set ("objects", ([
             "fish_scholar":OMONSTER"fish_scholar",
             "fish_general":OMONSTER"fish_general",
             ]) );
        set("light",1);
        reset();
}
