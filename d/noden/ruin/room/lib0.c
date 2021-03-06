// lib0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．大厅");
    set_long(@C_LONG
走进正门後，映入你眼帘的是一个宽敞幽静的大厅。地板是由黑的发亮的
石块所铺成，四周的墙壁和天花板上满布著美丽的壁画和精致的石雕。在旁边
有一座气派的弧型楼梯通往二楼，楼梯的扶把上也衬著光彩夺目的精美雕饰。
大厅的正中央有个水池 (pool) 散发著神秘的光芒，你不禁想走近看看。
C_LONG
    );
    set("exits", ([
	"out" : AREA"rose4",
	"up" : AREA"lib9"
	]));
    set("light", 1);
    set("item_desc", ([
	"pool" : @POOL
水池的中央有一尊女神像 (statue) ，神像的底座上有个小铜牌 (plate)。水
池里的水十分的清澈，周围的护栏上有著几个小洞。
POOL
,
	"statue" : @STATUE
这是一尊雕刻的栩栩如生的女神像，虽然她的容貌并不十分美丽，但是眉宇之
间隐隐透著一股威严。
STATUE
,
	"plate" : "铜牌上面写著：「女王的微笑」□希达．尼普顿。\n"
,
	"tube" : "这些水管被扣环牢牢地钉在水底。\n"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
    add_action("to_insert", "insert");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "pool")
	tell_object(p, "池底有几根水管 (tube)，不知道是做什麽用的。\n");
    else if (s == "tube")
    {
	tell_object(p, "有根水管似乎可以左右摇挣摇挣，有些不同。\n");
	p->set_temp("lilia1", 1);
    }
    else if (s == "hole")
        if (p->query_temp("lilia1") == 1)
	    tell_object(p, "护栏上有个小洞，似乎正对著那根水管。\n");
	else if (p->query_temp("lilia1") == 2)
	    tell_object(p, "小洞的下方似乎有个按钮，不细看还看不出来。\n");
	else
	    tell_object(p, "护栏上有些小洞，不知道是干什麽用的。\n");
    else
	return notify_fail("你想找什麽？这里这麽大可能要找到明年哦!\n");

    return 1;
}

int to_insert(string s)
{
    string src, dest;
    object p;
    p = this_player();

    if (!s)
	return notify_fail("Syntax: insert <obj1> into <obj2>\n");

    sscanf(s, "%s into %s", src, dest);
    if (src != "tube" || dest != "hole")
	return notify_fail("喂，控制一下，不要插错洞了 ....\n");
	p->set_explore("noden#45");
    p->set_temp("lilia1", 2);
    tell_object(p, "你把水管插进了洞里，但是它立刻又弹了回来。\n");
    return 1;
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s != "button" || p->query_temp("lilia1") != 2)
	return notify_fail("你想按什麽?\n");

    tell_object(p, @PUSH
当你按下按钮时，你发现神像正对著你微笑，令你魂摇神驰。当你回过神来的
时候，你发现周遭的景物已经变了。

PUSH
		);
    p->move_player(AREA"lib1", "SNEAK", "");
    return 1;
}

