// wenro2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Ͽ�ȵĵײ�");
    set_long(@C_LONG
��������һ��Ͽ�ȵĵײ�����������ǰ����һ���峹�ĺ�����ӳ��������
���ͱڵĵ�Ӱ���㲻�ɵ���������̾������������������������������ұ���
����������ش����������������������ƺ��и�С����
C_LONG
    );
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
	this_player()->move(AREA"wenro3");
    }

    return 1;
}
