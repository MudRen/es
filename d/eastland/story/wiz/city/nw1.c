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
���̵Ķ�������ǳ����ģ�����������·���ϱ���һ��Ǯׯ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
             "east" : SCITY"center",
             "west" : SCITY"wn1",
            "south" : SCITY"bank1"
        ]) );
        set( "objects", ([
           "policeman#1":SWMOB"wiz_guard2",
           "policeman#2":SWMOB"wiz_guard2",
           "policeman#3":SWMOB"wiz_guard2",
        ]) );
	reset();
}
