// wenro4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@C_LONG
��ǰ������һƬ�������֣������ﲻʱ��������ĸ���������֦ͷ����
����������֯��һ�����˵����¡���ԡ��������֮�У����ʱ���������泩��
�ѣ�Ҳ�����������ַ����߸衣
C_LONG
	    );
    set("exits", ([
	"west" : AREA"wenro5",
	"south" : AREA"wenro3"
	]));
    set("objects", (["bard" : MOB"bard"]));
    set("item_desc", ([
	"casablanca" : "��ˮ�ٺϣ����е�Ů����������ΰ��İ���\n"
	]));
    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_pick", "pick");
}

int do_search(string arg)
{
    write("���˽����ﳤ��Щ��ˮ�ٺ� (casablanca) ֮�⣬ûʲ���ر�Ķ�����\n");
    return 1;
}

int do_pick(string arg)
{
    object f;

    if (arg == "casablanca")
    {
        f = new(OBJ"casablanca");
        f->move(this_player());
        write("��ժ��һ����ˮ�ٺϡ�\n");
	return 1;
    }
    else if (arg == "flower")
	return notify_fail("����ժʲ�Ứ?\n");
    else	
	return notify_fail("������ʲ��?\n");
}

