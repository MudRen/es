#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڱ�����ϣ���������߷������죬�ϱ����Ƕ���֡�
��춱���ֵش�ƫƧ�������޳�����������ľϡϡ�����һ���ŵķ��Ӽ䣬������
�ģ��Եĸ����������䣬�ֵ����൱��������Ϊ��ס֮�ء�
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne2",
       	   "south" : SCITY"en1"
        ]) );
	reset();
}
