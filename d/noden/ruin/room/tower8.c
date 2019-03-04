// tower8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．第二层");
    set_long(@C_LONG
这里是魔术师塔的第二层，地板上画满了密密麻麻的奇特咒文，似乎是用
来禁制某种可怕的生物用的。空气中充满了腐尸的气味，你的直觉告诉你如果
不快点设法离开这个地方，恐怕不久之後你也会变成一具尸体了。
C_LONG
	    );
    switch(random(3))
    {
	case 0: set("exits", ([
		    "east" : AREA"tower9",
		    "south" : AREA"tower7"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
    }
    set("item_desc", (["ladder" : "一个通向上一层的梯子。\n"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_climb", "climb");
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
	write("你蹑手蹑脚地爬上梯子 ...\n");
        this_player()->move(AREA"tower10");
        return 1;
    }
    else
	return notify_fail("你想干什麽?\n");
}

