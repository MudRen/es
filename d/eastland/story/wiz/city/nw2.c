#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڱ�����ϣ�������������������졣��춱���ֵش�
ƫƧ�������޳�����������ľϡϡ�����һ���ŵķ��Ӽ䣬�������ģ��Եĸ�����
�����䣬�ֵ����൱��������Ϊ��ס֮�ء������߿�ͨ�����ſڣ��ϱ���һ��С��
�ӣ����������������ϣ�ԭ���Ǽ�˽�ӡ�
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nn",
            "west" : SCITY"wn2",
           "south" : SCITY"house2",
        ]) );
	reset();
}
