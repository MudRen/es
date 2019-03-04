// lib10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ����");
    set_long(@C_LONG
����һ���������鱾�ļ��Ӿ�Ȼ���������������󷿼����֪�����Ѿ�
�����˴�ͼ��ݵ�"����"��⡣������һƬ�麣�������ظ��ܵ�һ��ΰ����
����������Դ��Ҳ����Щ���������Ҳ˵����Ӵ��
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib11",
	"west" : AREA"lib9"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_read", "read");
}

int to_search()
{
    tell_object(this_player(), "������ǰ��������б���Ƥ���Ƿ����� .... ? ....\n");
    return 1;
}

int to_read(string s)
{
    if (s == "red book" || s == "��Ƥ��")
	cat(DIARY"redbook");
    else
	tell_object(this_player(), "�����ʲ��?\n");

    return 1;
}



