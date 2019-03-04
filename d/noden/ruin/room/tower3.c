// tower3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ������һ��");
    set_long(@C_LONG
������ħ��ʦ���ĵ�һ�㣬�ذ��ϻ���������������������ģ��ƺ�����
������ĳ�ֿ��µ������õġ������г����˸�ʬ����ζ�����ֱ�����������
������跨�뿪����ط������²���֮����Ҳ����һ��ʬ���ˡ�
C_LONG
	    );
    set("exits", ([
	"north" : AREA"tower2",
	"east" : AREA"tower2",
	"south" : AREA"tower2",
	"west" : AREA"tower2"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string arg)
{
    write("�㷢�ֵ����п�שͷ�ƺ���ĳ�����ŵİ�ť (button)��\n");
    return 1;
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "��������������ɢȥ .... �㷢�����ܵľ����Ѿ����� ....\n");
    p->move(AREA"tower4");
    return 1;
}

int to_push(string arg)
{
    if (arg == "button")
    {
	write("һ������Ѹ�ٵ�������������� ...\n");
        this_player()->set_temp("block_command", 1);
        call_out("recover", 15, this_player());
	return 1;
    }
    else
	return notify_fail("���밴ʲ��?\n");
}

