// tower0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ�������");
    set_long(@C_LONG
������ħ��ʦ������ڣ����ܶ�����������������ã���ɱ���ص�������
��ë���Ȼ��ħ��ʦ���Ĵ�����������ʯ��������д������·�պͲ���׼��
�롹��
C_LONG
	    );

    set("exits", (["north" : AREA"tower1"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object p;
   
    p = this_player(); 
    write("����ѽ�ҵأ���Ȼ�������ѿ���һ���� .... �ۡ�����\n");
    p->move(AREA"tower2");
    p->receive_damage(5);
    return 1;
}

