// tower4.c

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
    set("objects", (["jitter" : MOB"jitter"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    if (this_player()->query_temp("lilia_direction") == 1)
    {
	write("�㶨��һ�������߹�Ȼ�и�С�ţ������ؿ���̫��� ....\n");
	set("exits", (["west" : AREA"tower5"]));
        return 1;
    }
    else
        return 0;
}

