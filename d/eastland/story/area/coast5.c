#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ���ȴ����������������Ǹ߼�ͷ����ާ��ֲ������������Ҫʹ
����赹�ڵأ����������ֲ�����С�棬��ס�ض������ȫ�������ѹ��Ѽ���
�������Ҹ������ĵط���Ϣһ�£��ټ����ߣ���ù�һ�㡣
LONG
	);
	set("exits", ([ 
            "west" : SAREA"coast4"
        ]) );
        set("objects", ([
          "spider" : SMOB"spider1" 
        ]) ); 
	reset();
}
