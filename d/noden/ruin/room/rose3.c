// rose3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("��˹�����ǣ�����");
    set_long(@C_LONG
����վ��һ�����µĶ��ˣ��԰�����˹�����ǵĳ��š���ǰ���ԫ�бڵ�
�����Ȼ��ͬ������������ɺ�ΰ�ޱȣ���������������ħ��۹��ĻԻ͡���
���鷳���ǣ�Ҫ��ζɹ�������µ��԰��أ�
C_LONG
    );
    set("exits", (["south" : AREA"rose2"]) );

    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_read", "read");
    add_action("do_jump", "jump");
    add_action("do_answer", "answer");
}

int do_search()
{
    tell_object(this_player(), "�㷢�ֽ��²���һ��ʯ��������д��һЩ���֡�\n");
    return 1;
}

int do_read(string str)
{
    object p;
    p = this_player();

    if (str == "rune" || str == "runes")
    {
	if (p->query_temp("lilia_dic") == 1)
	    tell_object(p, "ʯ����д�������ش����Ů���ٹⳣ�项\n");
	else
	    return notify_fail("�㿴�˰��죬���ǲ�֪������дЩʲ�ᡣ\n");
    }
    else
	return notify_fail("�����ʲ��?\n");
    return 1;
}

int do_jump(string str)
{
    object p;
    p = this_player();

    if (!str || str != "down")
	return notify_fail("�����ʲ��? ���������Ļ����������Ŷ ...\n");
    else
    {
	tell_object(p, "�������ǰһԾ ....\n\n");
	tell_room(environment(p), sprintf("%s�ܳ嶯�������µ�������ȥ ....\n", p->query("c_name")), ({p}));
	tell_object(p, "�㱻ˮ���嵽һ���µĵط� ....\n\n");
	p->move("/d/noden/11,6.noden");
    }

    return 1;
}

int do_answer(string str)
{
    object p;
    p = this_player();
	
    if (str == "֥�鿪��" || str == "open sesame")
    {
	if (p->query_temp("lilia_dic") != 1)
	    return notify_fail("��ͻȻ�����㻹û���ֵ䣬����ȥҲû�ã���Ǿ�Ӳ�����ذ�˵��һ��Ļ����˻�ȥ��\n");
	p->set_explore("noden#47");
	tell_object(p, "��Ȼһ���ɫ�Ĺ�â�����������ܣ�����ɢȥʱ���㷢�����ܵľ����Ѿ�����!\n");
	p->move_player(AREA"rose4", ({"%s��һ���׹⴫������!\n", "%s������һ����â���������\n"}), "");
    }
    else
	return notify_fail("Ů��������������˷�����������������Ͳ�Ҫ������ ok?��\n");
    return 1;
}

