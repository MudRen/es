// lib7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．秘室");
    set_long(@C_LONG
这是一间阴暗的小房间，里面的摆设虽然简单，但是却不失一种高雅的韵
致，充份显露出主人的良好教养及品味。房间的天花板是个闪烁著光芒的魔法
力场，墙角的桌上有著一本书 (book) 不知道写些什麽。
C_LONG
    );
    set("exits", (["up" : AREA"lib6"]));
    set("item_desc", (["book" : "好像是某人的日记，或许你可以阅读它。\n"]));
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
	return notify_fail("你想读什麽?\n");

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
	    return notify_fail("日记上没有这一页。\n");
    }
}

