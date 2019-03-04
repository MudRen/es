// tower10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("ħ��ʦ������һ��");
    set_long(@C_LONG
��������ħ��ʦ���ĵ�һ�㣬����ĵذ岢�������������ĵط�һ    
�㻭�������ģ�����һƽ�羵ʲ�ᶫ����û�С��ذ�����Ʈ����һ�ŷ�
�����ˮ����ˮ������ͷ�ƺ���Щ��ֵ�ͼ����
C_LONG
    );
    set("exits", ([
	"up" : AREA"tower1"
	]) );
    set("light", 1);
    set("item_desc", ([
	"ladder" : "һ�����µ����ӡ�\n"
	]) );
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_climb", "climb");
    add_action("to_search", "search");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 7)
    {
        return notify_fail("���Ѿ�����һ���ˣ���ʡʡ�����ɡ�\n");
    }

    p->set(QUESTNAME, 7);
    tell_object(p, "��С������ذ�������֮ӡ�����ħ���ֵ�ıʼ����\n");
    return 1;
}

int to_search()
{
    write("�㷢��ǽ���и����� (ladder)��\n");
    return 1;
}

int to_climb(string arg)
{
    if (arg == "ladder")
    {
        write("��������ŵ��������� ...\n");
        this_player()->move(AREA"tower8");
        return 1;
    }
    else
        return notify_fail("�����ʲ��?\n");
}
