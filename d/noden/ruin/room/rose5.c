// rose5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("���з���");
    set_long(@C_LONG
��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣���д������
�ﱻ�����Ѹ������ˡ���Ƭ���������ľ���ͳ��Ÿ�����ΰ�����Ľ������Ǹ�
��Ϊ��̵ĶԱȣ����ֱ�������㻹�������߲����ҵ���·��
C_LONG
    );
    set("exits", (["south" : AREA"rose4"]) );
    set("item_desc", ([
	"door" : @DESC
�����ϻ��˲�����ֵ�ͼ��������������ĳ�����ĵ�Ϳѻ�����Ա߻�ɢ����
���ٵ�ľ̿���ƺ���������Ϳѻ (draw) �õġ�
DESC
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_draw", "draw");
    add_action("to_open", "open");
}

int to_search(string s)
{
    if (s == "door")
    {
	write("�������ƺ��з������ ....\n");
    }
    else
    {
        write("�����ѵ������ƺ��и����� ....\n");
    }
    return 1;
}

int to_draw(string s)
{
    object p;
    p = this_player();

    if (!s)
	return notify_fail("��ʲ�ử��ʲ�����棿(draw A on B)\n");

    if (s == "seal on door" || s == "seal o pallass on door" ||
	s == "Seal o Pallas on door")
    {
	if (p->query(QUESTNAME) >= 2)
	{
	    tell_object(p, "��С������ذѰ���˹֮ӡ���������� ...\n");
	    p->set_temp("lilia_wind", 1);
	    return 1;
	}
    }
    return notify_fail("���뻭ʲ�᣿\n");
}

int to_open(string s)
{
    object p;
    p = this_player();

    if (s == "door")
    {
	if (p->query_temp("lilia_wind") != 1)
	    return notify_fail("���þ��˳��̵����������Ǵ򲻿�����š�\n");
	p->delete_temp("lilia_wind");
	tell_object(p, "������ָ������Űѵ�ʱ���ź�Ȼ�Զ��ش򿪣�һ���罫��������!\n");
	p->move(AREA"eda0");
	p->receive_damage(5);
        return 1;
    }
    else 
	return notify_fail("���뿪ʲ�᣿\n");
}    
