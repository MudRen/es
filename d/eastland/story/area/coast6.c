#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ���ȴ����������������Ǹ߼�ͷ����ާ��ֲ������������Ҫʹ
����赹�ڵأ����������ֲ�����С�棬��ס�ض������ȫ�������ѹ��Ѽ���
�������Ҹ������ĵط���Ϣһ�£��ټ����ߣ���ù�һ�㡣���㶫����һ��С��
ԭ��
LONG
	);
	set("exits", ([ 
             "east" : SAREA"plain1",
       	    "north" : SAREA"coast4" 
        ]) );
        set("objects", ([
           "insect#1" : SMOB"insect1",
           "insect#2" : SMOB"insect1",
           "insect#3" : SMOB"insect1",
           "insect#4" : SMOB"insect1",
        ]) );
	reset();
}
