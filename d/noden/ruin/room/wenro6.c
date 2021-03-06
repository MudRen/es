// wenro6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("奇异的空间");
    set_long(@C_LONG
你现在一片虚无之中，只有一颗发著动人光芒的透明水晶陪著你。
水晶的上头似乎有些奇怪的图案。
C_LONG
    );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_search", "search");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 6)
    {
        return notify_fail("你已经画过一次了，就省省力气吧。\n");
    }

    p->set(QUESTNAME, 6);
    tell_object(p, "你小心翼翼地把希特斯之印描绘在魔法字典的笔记栏里。\n");
    return 1;
}

int to_search()
{
    write("你四处不停地寻找，到底想找些什麽呢?\n");
    this_player()->move(AREA"rose4");
    return 1;
}
