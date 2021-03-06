// entrance 3

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("地下水道");
    set_long(@C_LONG
这里是一个似乎已经废弃很久的输水道，空气中飘浮著一股令人不适的味
道。但是奇怪的是，这麽潮湿的地方连一只蟑螂都没有。你的面前有一条湍急
的小溪，南边的墙上画著一堆奇怪的符号，上面还有根扳杆 (lever)。
C_LONG
    );
    set("exits", ([
	"east" : AREA"en1",
	]) );
    set("item_desc", ([
        "lever" : "这根扳杆不知道是什麽开关，你或许可以拉 (pull) 它。\n",
        "wall" : "这墙上画著一堆奇怪的符号，或许是某种文字也说不定。\n"
        ]) );
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_swim", "swim");
    add_action("to_search", "search");
}

int to_pull(string str)
{
    object p;
    p = this_player();

    if (str == "lever")
    {
	tell_object(p, "你拉了一下扳杆，但是它马上又弹回原来的位置，似乎什麽事情都没有发生。\n");
	p->set_temp("lilia_0", 3);
	return 1;
    }
    else
	return notify_fail("你想拉什麽?\n");
}

int to_swim()
{
    object p;
    p = this_player();

    tell_object(p, "你正准备下水时，忽然脚下一个踩空 ... 哇～～～\n");
    tell_object(p, "\n你被水流冲到一个新的地方 ....\n\n");
    switch (p->query_temp("lilia_0"))
    {
	case 1:
	    p->move("/d/noden/11,6.noden");
	    p->delete_temp("lilia_0");
	    break;
	case 2:
	    p->move(AREA"en4");
	    break;
	case 3:
	    p->move(AREA"en5");
	    break;
    }
    return 1;
}

int to_search()
{
    string dir;
    switch (this_player()->query_temp("lilia_0"))
    {
        case 1: dir = "下";
                break;
        case 2: dir = "东北";
                break;
        case 3: dir = "东北东";
                break;
    }
    write("除了流向"+dir+"方的水道外，什麽东西都没有。\n");
    return 1;
}

