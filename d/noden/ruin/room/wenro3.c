// wenro3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Ͽ�ȵĵײ�");
    set_long(@C_LONG
��������һ��Ͽ�ȵĵײ����������������һƬ�߸ߵ�ɽ�ڣ���ͷ����ʯ
����������â���㲻�ɵ���������̾�������������������������᷽���ұ���
����Щ����ش����������������������ƺ��и�С����
C_LONG
    );
    set("exits", (["north" : AREA"wenro4"]));
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string s)
{
    if (!s || s != "hole")
	return notify_fail("�����������?\n");
    else
    {
	write("�㴩���ұ����С��������һ���µĵط� ...\n");
	this_player()->move(AREA"wenro2");
    }

    return 1;
}
