// entrance 3

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����ˮ��");
    set_long(@C_LONG
������һ���ƺ��Ѿ������ܾõ���ˮ����������Ʈ����һ�����˲��ʵ�ζ
����������ֵ��ǣ����ᳱʪ�ĵط���һֻ��붼û�С������ǰ��һ���ļ�
��СϪ���ϱߵ�ǽ�ϻ���һ����ֵķ��ţ����滹�и���� (lever)��
C_LONG
    );
    set("exits", ([
	"east" : AREA"en1",
	]) );
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
	tell_object(p, "������һ�°�ˣ������������ֵ���ԭ����λ�ã��ƺ�ʲ�����鶼û�з�����\n");
	p->set_temp("lilia_0", 3);
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
    tell_object(p, "\n�㱻ˮ���嵽һ���µĵط� ....\n\n");
    switch (p->query_temp("lilia_0"))
    {
	case 1:
	    p->move("/d/noden/11,6.noden");
	    p->delete_temp("lilia_0");
	    break;
	case 2:
	    p->move(AREA"en4");
	    break;
	case 3:
	    p->move(AREA"en5");
	    break;
    }
    return 1;
}

int to_search()
{
    string dir;
    switch (this_player()->query_temp("lilia_0"))
    {
        case 1: dir = "��";
                break;
        case 2: dir = "����";
                break;
        case 3: dir = "������";
                break;
    }
    write("��������"+dir+"����ˮ���⣬ʲ�ᶫ����û�С�\n");
    return 1;
}

