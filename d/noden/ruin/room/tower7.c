// tower7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ�����ڶ���");
    set_long(@C_LONG
������ħ��ʦ���ĵڶ��㣬�ذ��ϻ���������������������ģ��ƺ�����
������ĳ�ֿ��µ������õġ������г����˸�ʬ����ζ�����ֱ�����������
������跨�뿪����ط������²���֮����Ҳ����һ��ʬ���ˡ�
C_LONG
	    );
    switch(random(3))
    {
	case 0: set("exits", ([
		    "east" : AREA"tower8",
		    "south" : AREA"tower6"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower8",
                    "south" : AREA"tower6"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower8",
                    "south" : AREA"tower6"
                    ]));
                break;
    }
    reset();
}


