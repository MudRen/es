#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����ĵ�·");
	set_long( @LONG
�����ǡ����̹��������ĵ�·��ͬʱҲ�Ǵ�ٹ��˾�ס�ĵط���������������
�����������ϻ����������֮���������ѱ���һ�������ɺ����Ľ��������
�ĸ��Ӹ����ûʡ��������ϱߵ�·�Ի�����һ����ˮ�أ���񹤾���������춵���
���̵Ķ�������ǳ����ģ������Ƕ���·��
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"en1",
       	    "west" : SCITY"center",
           "north" : SCITY"house1"
        ]) );
	reset();
}
