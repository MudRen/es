// wenro6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����Ŀռ�");
    set_long(@C_LONG
������һƬ����֮�У�ֻ��һ�ŷ������˹�â��͸��ˮ�������㡣
ˮ������ͷ�ƺ���Щ��ֵ�ͼ����
C_LONG
    );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_search", "search");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 6)
    {
        return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 6);
    tell_object(p, "��С������ذ�ϣ��˹֮ӡ�����ħ���ֵ�ıʼ����\n");
    return 1;
}

int to_search()
{
    write("���Ĵ���ͣ��Ѱ�ң���������Щʲ����?\n");
    this_player()->move(AREA"rose4");
    return 1;
}
