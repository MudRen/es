//emsd.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@C_LONG
����һ���ûƽ���ɵ������õĹ�â���䣬����������и���̳
(altar),��̳���и�������һ����С��ׯ�ϵ�����(statue)��������
�������̵���ʥ֮�ء�
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
        "altar" : "һ������������ʯ��̵ļ�̳��Ҳ����Թ��� (gongxian) Щʲ�ᡣ\n",
        "statue" : "һ���̵����������Ľ��ں�ѻ�ĵ������϶����¡�\n"
	]));
    reset();
}

void init()
{
    add_action("do_gongxian", "gongxian");
    add_action("do_bow", "bow");
}

int do_dedicate()
{
    object f; 
    if (f = present("torch", this_player()))
    {
        write("��ѻ���ϵĹ����ڼ�̳�ϡ�\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
        return notify_fail("������û��ʲ��ɹ���Ķ���,��ѻ���۾�����գ��գ��\n");
}

int do_bow(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
            write("�㷢�����ɶ�������ݺݵص����㣬С�����ƨƨ��\n");
	    return 1;
	}
        else    
	{
            write("���ϵ����������һ����ͻȻ��һ������Ĳʺ�ע��������� ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
        return notify_fail("������ʲ��?\n");
}

