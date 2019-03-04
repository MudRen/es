// g8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ļ�԰");
    set_long(@C_LONG
��������һ�������Ļ�԰�������������Ӳݺ���̦������Ŀ�����������
ɱ�����գ��ƺ��������ϵ�ѪҺҲ��ҪΪ֮�����������Ӳ����ƺ�������һ��
ʲ�ᶫ���������㿴�������
C_LONG
	    );
    set("exits", ([
	"south" : AREA"g2"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_sketch", "sketch");
}

int to_search()
{
    write("�ݴ�����һ��������������ɫˮ����ˮ������ͷ����ֵ�ͼ����\n");
    return 1;
}


int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 5)
    {
        return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 5);
    tell_object(p, "��С������ذѺ�����֮ӡ�����ħ���ֵ�ıʼ����\n");
    return 1;
}

