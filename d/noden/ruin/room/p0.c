// p0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��鿲�������������");
    set_long(@C_LONG
��ǰ������һƬ�����ľ��󣬽��޵���ˮ�ٺ�ӳ��Ρ��������������г�
����������������Լ���������������Ӱ����������ʱ���������泩��
�ѡ�
C_LONG
	    );
    set("exits", ([
	"north" : AREA"p1"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write("�����������������Ů�����޹�����������ֵĵط� :p\n");
    return 1;
}

