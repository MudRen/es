// lib11.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�������");
    set_long(@C_LONG
����һ�������������������ҵ���Ȥ���䣬��Ϊ����ĵذ��ϻ���һ��ͼ��
��������ע�⣺���۹�����ͼ�������������Ϊ���ŵ�ͼ�ų����������ɣ�����
���ɵô����������������
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib12",
	"west" : AREA"lib10",
	"north" : AREA"lib13",
	"south" : AREA"lib14",
	"up" : AREA"lib15"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s != "map")
	return notify_fail("������ʲ��? ������������Ҫ�ҵ�����Ӵ ...\n");

    if (p->query(QUESTNAME) >= 7)
    {
	tell_object(p, "��������ע���������ͼʱ����е�һ����ѣ ...\n");
	p->move(AREA"p0");
    }
    else
	tell_object(p, "����һ�ź������ĵ�ͼ��������ɽ��ˮ�������� ...\n");

    return 1;
}
