#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڱ�����ϣ�������������������졣��춱���ֵش�
ƫƧ�������޳�����������ľϡϡ�����һ���ŵķ��Ӽ䣬�������ģ��Եĸ�����
�����䣬�ֵ����൱����������һ��ͯŮ׷����Ϸ�⣬��Ϊ��ס֮�ء������߿���
���ﱱ�ſڡ�
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"en2",
       	    "west" : SCITY"nn",
        ]) );
	reset();
}
