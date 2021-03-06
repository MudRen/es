// tower10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．第一层");
    set_long(@C_LONG
你现在在魔术师塔的第一层，这里的地板并不像塔里其他的地方一    
般画满了咒文，反而一平如镜什麽东西都没有。地板中央飘浮著一颗发
光的紫水晶，水晶的上头似乎有些奇怪的图案。
C_LONG
    );
    set("exits", ([
	"up" : AREA"tower1"
	]) );
    set("light", 1);
    set("item_desc", ([
	"ladder" : "一个向下的梯子。\n"
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
        return notify_fail("你已经画过一次了，就省省力气吧。\n");
    }

    p->set(QUESTNAME, 7);
    tell_object(p, "你小心翼翼地把莉莉雅之印描绘在魔法字典的笔记栏里。\n");
    return 1;
}

int to_search()
{
    write("你发现墙角有个梯子 (ladder)。\n");
    return 1;
}

int to_climb(string arg)
{
    if (arg == "ladder")
    {
        write("你蹑手蹑脚地爬下梯子 ...\n");
        this_player()->move(AREA"tower8");
        return 1;
    }
    else
        return notify_fail("你想干什麽?\n");
}
