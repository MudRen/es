// wenro5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��̳");
    set_long(@C_LONG
�����и������ֻ������ļ�̳ (altar)����̳���и�������һ����С����
������ (statue) ����Ȼ���·ǳ����������������ܾ��ÿ�����������һ����
�����ݵ��������գ���ǰͷ�Ļ�����Ϣ��Ȼ��ͬ���������ѵ����Ǹ���������
�ɵ���
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
	"altar" : "һ������ʯ��̳��Ҳ����Թ��� (dedicate) Щʲ�ᡣ\n",
	"statue" : "һ���̵�������������Ů����\n"
	]));
    reset();
}

void init()
{
    add_action("do_dedicate", "dedicate");
    add_action("do_kiss", "kiss");
}

int do_dedicate()
{
    object f; 
    if (f = present("casablanca", this_player()))
    {
	write("�����ˮ�ٺϹ����ڼ�̳�ϡ�\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
	return notify_fail("������û��ʲ��ɹ���Ķ�����\n");
}

int do_kiss(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
	    write("�㷢�ֿ�������ݺݵص����㣬���Ǳ��׵ĺá�\n");
	    return 1;
	}
        else    
	{
	    write("�������������һ�����������ͻȻ��е�һ��������ת ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
	return notify_fail("������ʲ��?\n");
}

