// wenro1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Ͽ�ȵĵײ�");
    set_long(@C_LONG
��������һ��Ͽ�ȵĵײ�����������ǰ����һ���峹�ĺ�����ӳ��������
���ͱڵĵ�Ӱ���㲻�ɵ���������̾������������������������������ұ���
����������ش����������������������ƺ��������֡�
C_LONG
    );
    set("exits", (["west" : AREA"wenro2"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_swim", "swim");
}

int to_search()
{
    write("�ұ���д������Ӧ����������˶��������ڴ���Ӿ��\n");
    return 1;
}

int to_swim()
{
    write("�㲻�Ѵ���֮�����ε��˶԰� ....\n");
    this_player()->move(AREA"wenro0");
    return 1;
}

