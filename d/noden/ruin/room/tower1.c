// tower1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ��������");
    set_long(@C_LONG
������ħ��ʦ���ĳ��ڣ����ܶ�����������������ã���ɱ���ص�������
��ë���Ȼ�����ڵĴ�����������ʯ��������д������HASLAVISTA BABY!����
C_LONG
	    );

    set("exits", (["north" : AREA"tower0"]));
    set("item_desc", ([
	"slab" : "һ����Ƶ�ʯ��������д������������������\n"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_search(string arg)
{
    write("���������ң�ֻ���������п�Сʯ�� (slab)��\n");
    return 1;
}

int to_pray()
{
    write("�������������Щʲ����? ....\n");
    this_player()->move(AREA"rose4");
    return 1;
}

