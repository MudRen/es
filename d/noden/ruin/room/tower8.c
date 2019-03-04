// tower8.c

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
		    "east" : AREA"tower9",
		    "south" : AREA"tower7"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
    }
    set("item_desc", (["ladder" : "һ��ͨ����һ������ӡ�\n"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_climb", "climb");
}

int to_search()
{
    write("�㷢��ǽ���и����� (ladder)��\n");
    return 1;
}

int to_climb(string arg)
{
    if (arg == "ladder")
    {
	write("��������ŵ��������� ...\n");
        this_player()->move(AREA"tower10");
        return 1;
    }
    else
	return notify_fail("�����ʲ��?\n");
}

