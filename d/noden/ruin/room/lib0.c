// lib0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
�߽������ᣬӳ������������һ�����ľ��Ĵ������ذ����ɺڵķ�����
ʯ�����̳ɣ����ܵ�ǽ�ں��컨���������������ıڻ��;��µ�ʯ�����Ա�
��һ�����ɵĻ���¥��ͨ����¥��¥�ݵķ�����Ҳ������ʶ�Ŀ�ľ������Ρ�
�������������и�ˮ�� (pool) ɢ�������صĹ�â���㲻�����߽�������
C_LONG
    );
    set("exits", ([
	"out" : AREA"rose4",
	"up" : AREA"lib9"
	]));
    set("light", 1);
    set("item_desc", ([
	"pool" : @POOL
ˮ�ص�������һ��Ů���� (statue) ������ĵ������и�Сͭ�� (plate)��ˮ
�����ˮʮ�ֵ��峺����Χ�Ļ�������������С����
POOL
,
	"statue" : @STATUE
����һ���̵�����������Ů������Ȼ������ò����ʮ������������ü��֮
������͸��һ�����ϡ�
STATUE
,
	"plate" : "ͭ������д������Ů����΢Ц����ϣ����ն١�\n"
,
	"tube" : "��Щˮ�ܱ��ۻ����εض���ˮ�ס�\n"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
    add_action("to_insert", "insert");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "pool")
	tell_object(p, "�ص��м���ˮ�� (tube)����֪������ʲ���õġ�\n");
    else if (s == "tube")
    {
	tell_object(p, "�и�ˮ���ƺ���������ҡ��ҡ������Щ��ͬ��\n");
	p->set_temp("lilia1", 1);
    }
    else if (s == "hole")
        if (p->query_temp("lilia1") == 1)
	    tell_object(p, "�������и�С�����ƺ��������Ǹ�ˮ�ܡ�\n");
	else if (p->query_temp("lilia1") == 2)
	    tell_object(p, "С�����·��ƺ��и���ť����ϸ��������������\n");
	else
	    tell_object(p, "��������ЩС������֪���Ǹ�ʲ���õġ�\n");
    else
	return notify_fail("������ʲ�᣿������������Ҫ�ҵ�����Ŷ!\n");

    return 1;
}

int to_insert(string s)
{
    string src, dest;
    object p;
    p = this_player();

    if (!s)
	return notify_fail("Syntax: insert <obj1> into <obj2>\n");

    sscanf(s, "%s into %s", src, dest);
    if (src != "tube" || dest != "hole")
	return notify_fail("ι������һ�£���Ҫ����� ....\n");
	p->set_explore("noden#45");
    p->set_temp("lilia1", 2);
    tell_object(p, "���ˮ�ܲ���˶�������������ֵ��˻�����\n");
    return 1;
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s != "button" || p->query_temp("lilia1") != 2)
	return notify_fail("���밴ʲ��?\n");

    tell_object(p, @PUSH
���㰴�°�ťʱ���㷢��������������΢Ц�������ҡ��ۡ�����ع�������
ʱ���㷢������ľ����Ѿ����ˡ�

PUSH
		);
    p->move_player(AREA"lib1", "SNEAK", "");
    return 1;
}

