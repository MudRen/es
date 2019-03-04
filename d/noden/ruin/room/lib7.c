// lib7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ͼ��ݣ�����");
    set_long(@C_LONG
����һ��������С���䣬����İ�����Ȼ�򵥣�����ȴ��ʧһ�ָ��ŵ���
�£������¶�����˵����ý�����Ʒζ��������컨���Ǹ���˸����â��ħ��
������ǽ�ǵ���������һ���� (book) ��֪��дЩʲ�ᡣ
C_LONG
    );
    set("exits", (["up" : AREA"lib6"]));
    set("item_desc", (["book" : "������ĳ�˵��ռǣ�����������Ķ�����\n"]));
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_read", "read");
}

int to_read(string s)
{
    int page;

    if (!s)
	return notify_fail("�����ʲ��?\n");

    if (s == "book" || s == "diary")
    {
	cat(DIARY"diary1");
	return 1;
    }
    else if (sscanf(s, "page %d", page) == 1)
    {
	if (file_exists(DIARY"diary" + page))
	{
	    cat(DIARY"diary" + page);
	    return 1;
	}
	else
	    return notify_fail("�ռ���û����һҳ��\n");
    }
}

