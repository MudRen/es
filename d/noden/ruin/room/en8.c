// entrance 8

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ˮ��");
    set_long(@C_LONG
������һ���ƺ��Ѿ������ܾõ���ˮ����������Ʈ����һ�����˲��ʵ�ζ
����������ֵ��ǣ����ᳱʪ�ĵط���һֻ��붼û�С������ǰ��һ���ļ�
��СϪ�����ߵ�ǽ�ϻ���һ����ֵķ��ţ����滹�и���� (lever)��
C_LONG
    );
    set("item_desc", ([
        "lever" : "�����˲�֪����ʲ�Ὺ�أ����������� (pull) ����\n",
        "wall" : "��ǽ�ϻ���һ����ֵķ��ţ�������ĳ������Ҳ˵������\n"
        ]) );
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_swim", "swim");
    add_action("to_search", "search");
}

int to_pull(string str)
{
    object p;
    p = this_player();

    if (str == "lever")
    {
	tell_object(p, "������һ�°�ˣ������������ֵ���ԭ����λ�ã��ƺ�ʲ�����鶼û�з��� ....\n");
	p->delete_temp("lilia_0");
	tell_object(p, "��? �ذ�ʲ��ʱ�򲻼���? ... �ۡ�����\n");
	tell_room(environment(p), "������һ���ҽУ����������ҿ�������������ʲ���·��� ....\n", ({p}));
	p->set_explore("noden#44");

	p->move(AREA"rose0");
	return 1;
    }
    else
	return notify_fail("������ʲ��?\n");
}

int to_swim()
{
    object p;
    p = this_player();

    tell_object(p, "����׼����ˮʱ����Ȼ����һ���ȿ� ... �ۡ�����\n");
    switch (p->query_temp("lilia_0"))
    {
	case 6:
	    p->move(AREA"en6");
	    break;
	default:
	    p->move(AREA"en1");
	    break;
    }
    return 1;
}

int to_search()
{
    write("���������Ϸ���ˮ���⣬ʲ�ᶫ����û�С�\n");
    return 1;
}

