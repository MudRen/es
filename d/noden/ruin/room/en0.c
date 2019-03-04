// entrance 0

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�״��ĹѨ");
    set_long(@C_LONG
��������һ���ڰ���ʪ�Ķ�Ѩ�������ֵ�����Ȼ�������������ص�ʪ
����ǽ����ȴ��һ����̦Ҳû�С���������ɭɭ�Ķ�Ѩ��㲻�ɵô��˸�
���������ս .... ����û��ǸϿ��뿪�����ط��ȽϺá�
C_LONG
    );
    set("item_desc", ([
	"face" : "��ʯ�������̵ĺ��Ǿ������㲻���������� ....\n",
	"statue" : "��ʯ���̵ĺ��Ǿ��£����������е����ħ�塣\n",
	"wall" : "���ߵ�ǽ���ƺ�Ƕ��һ��ʯ�񣬲����㿴�������������\n",
	"board" : @BB
��ʾ������д����

	����һ��ȫ�µ����򣬰�����һ���ǳ����Ѷȵ���������������
    ������ס�����ٵ���ʦ������������Ҳ����������ĳ�·�Ļ��������
     pray ���������ܵ����������͵���ȫ�ĵط�ȥ��

	���������������һ���׶�֮�����Դ��棬�ڵ����׶�֮����춺�
    ���޳�ǩ��������Լ�����������С�ĵĻ������ܻ�ֱ�ӻ�Զ����¶��Ӣ
    �۹�ȥ��ϣ���������⡣���Ͱɣ�Ŭ��ȥ������� 

				����ʦ  Ů�� (Lilia) 
BB
	]) );
    reset();
}

void init()
{
    add_action("to_touch", "touch");
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "face")
    {
	tell_object(p, "ʯ����۾�ͻȻ������һ�������Ĺ�â�������㣬�㷢���Լ������͵���ĵط�!\n");
	if (p->query(QUESTNAME) >= 1)
	    p->move_player(AREA"rose0", ({"%s��һ�����Ĺ�â��������!\n", "%s������һ���â���������\n"}), "" );
	else
	{
	    p->set_temp("lilia_0", 1);
	    p->move_player(AREA"en1", ({"%s��һ�����Ĺ�â��������!\n", "%s������һ���â���������\n"}), "" );
	}
	return 1;
    }
    else
	return notify_fail("������ʲ��? ��������ǲ��õ���ΪŶ ....\n");
}

int to_search()
{
    write("ǽ���ƺ�����һ���ʾ�� (board)��\n");
    return 1;
}

int to_pray()
{
    write("��������� .... ��Щʲ�����? ....\n");
    this_player()->move("/d/noden/nodania/sealroom");
    return 1;
}
