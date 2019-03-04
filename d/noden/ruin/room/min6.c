// min6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�������");
    set_long(@C_LONG
���������������������һƬ�տ�������ֻ���ؾ���ǽ�ں���
���徲���������������ĺ���������˷����������������Щ���䡣��
�����������磿��������в��ɵ���������  
C_LONG
    );
    set("item_desc", ([
	"plate" : "һ��СС��ľ�ƣ���ͷд������������������֮�ڡ�\n",
	"button" : "�����������ɫ�İ�ť��\n"
	]) );
	
    set("exits", ([
	"north" : AREA"min7",
	"south" : AREA"min5"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int exits_open()
{
    if (this_player()->query_temp("lilia_pass") == 3)
    {
	write("���������Ȼӿ��һ������������������׵ش�������ǽ��\n");
    	return 0;
    }
    else
    {
	write("һ�����ε�������ס���ȥ��\n");
	return 1;
    }
}

int to_search(string s)
{
    if (!s)
    {
	write("���������ң����ֵ����ƺ��п�Сľ�� (plate)��\n");
	return 1;
    }
    else if (s == "plate")
    {
	write("Сľ��������������ť (button)��\n");
	return 1;
    }
    else if (s == "button")
    {
	write("��������ť������ɫ��ͬ��������С��״��һ����\n");
	return 1;
    }
    else
	return notify_fail("������ʲ�᣿�������ûʲ�ᶫ���� ...\n");
}

int to_push(string s)
{
    string color;
    object p;
    int order;

    if (!s)
    {
	return notify_fail("���밴ʲ�᣿\n");
    }

    sscanf(s, "%s button", color);
    p = this_player();
    order = p->query_temp("lilia_pass");

    switch (color)
    {
	case "red": 
	    if (order == 4)
		p->set_temp("lilia_pass", 5);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	
	case "blue":
	    p->set_temp("lilia_pass", 4);
	    break;

	case "yellow":
	    if (order == 5)
		p->set_temp("lilia_pass", 3);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	default:
	    return notify_fail("���밴ʲ����ɫ�İ�ť?\n");
     }

     write("�㰴�°�ť�������ƺ�ʲ���¶�û�з��� ...\n");
     return 1;
}
        
