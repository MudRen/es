// lib8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
����һ���տ������ķ��䣬���������Ʈ����һ�������ĺ�ˮ��������ϸ
һ�ƣ�ˮ���ϻ�������ֵ�ͼ�������ߵ�ǽ�Ͽ���һЩ���� (runes)��������
һ��ħ���������ƺ�����ͨ�������ӡ�
C_LONG
    );
    set("exits", (["north" : AREA"lib6"]));
    set("item_desc", ([
	"runes" : @RUNE
�ɾ�����ʿ��

    ��ˮ���ϵ�ͼ�����Ǵ�˵�е���ͻ��֮ӡ������԰������ (sketch) ��
������������ϣ��Ϳ��Ի�÷�ӡ֮�ŵ��Ͽɣ�������ӡ֮�ŵ��ﱻ��ӡ�ĵ�
��ȥ��

    Ը����Ů���ٹⳣ�����ҡ�

					ϣ����ն�
RUNE
	]) );
    
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
}

int to_sketch()
{
    object p;
    p = this_player();
    
    if (p->query(QUESTNAME) >= 1)
    {
	return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 1);
    tell_object(p, "��С������ذ���ͻ��֮ӡ�����ħ���ֵ�ıʼ����\n");
    write("[������� ʧ��ķ�ӡ ��һ�׶ε����񣬻�� 5000 �㾭��]\n");
    this_player()->finish_quest(QUESTNAME, 1);
    this_player()->gain_experience(5000);
    return 1;
}

