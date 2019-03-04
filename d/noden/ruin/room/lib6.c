// lib6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
���������һ�������������ϣ�����ʯ�̳ɵ��ߵ����������졣����ǽ  
�����и�Сͭ�����ƺ���ĳ�ֿ��� (switch) �����ȵ�ǽ�ڲ�֪����ʲ�ᶫ��
������ģ���ҫ�������Ĺ�â��
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib5",
	]) );
    set("item_desc", ([
	"wall" : "ǽ�ϻ���һ�������ǿ���Ķ��� .... �� :D~~~~\n",
	"switch" : "���ͭ����������� (pull) ������ ....\n"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_search", "search");
}

int to_pull(string s)
{
    object p;
    p = this_player();

    if (s == "switch")
    {
	tell_object(p, @NOTHING
��С�ĵ�����ͭ���������ƺ�ʲ�����鶼û�з��� .....
..............

�ذ�����ֲ����˵����� .....
..............

�ۡ�����

NOTHING
	);
	p->move(AREA"lib7");
        tell_room(environment(p), "������һ���ҽУ����������ҿ�������������ʲ���·��� ....\n", ({p}));
        return 1;
    }
    else
	return notify_fail("������ʲ��?\n");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "south")
    {
	tell_object(p, @OK
���㶢���ϱ�ǽ�ϻ��Ŀ��⴮����ˮ��ʱ�򣬺�Ȼ����ǽ���и���ť�����
��˳��һ�� .... 

�����ǰͻȻǿ��һ��������ָ��Ӿ�ʱ���㷢�����ܵľ����Ѿ����� ....

OK
	);
	p->move(AREA"lib8");
	return 1;
    }
    else return notify_fail("������ʲ��? ������ʲ����Ȥ�Ķ�����?\n");
}

