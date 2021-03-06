// rose5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在这
里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑真是个
极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
C_LONG
    );
    set("exits", (["south" : AREA"rose4"]) );
    set("item_desc", ([
	"door" : @DESC
秘门上画了不少奇怪的图案，看起来像是某种无聊的涂鸦。门旁边还散落了
不少的木炭，似乎就是拿来涂鸦 (draw) 用的。
DESC
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_draw", "draw");
    add_action("to_open", "open");
}

int to_search(string s)
{
    if (s == "door")
    {
	write("门後面似乎有风的声音 ....\n");
    }
    else
    {
        write("瓦砾堆的下面似乎有个秘门 ....\n");
    }
    return 1;
}

int to_draw(string s)
{
    object p;
    p = this_player();

    if (!s)
	return notify_fail("把什麽画在什麽上面？(draw A on B)\n");

    if (s == "seal on door" || s == "seal o pallass on door" ||
	s == "Seal o Pallas on door")
    {
	if (p->query(QUESTNAME) >= 2)
	{
	    tell_object(p, "你小心翼翼地把巴拉斯之印画在秘门上 ...\n");
	    p->set_temp("lilia_wind", 1);
	    return 1;
	}
    }
    return notify_fail("你想画什麽？\n");
}

int to_open(string s)
{
    object p;
    p = this_player();

    if (s == "door")
    {
	if (p->query_temp("lilia_wind") != 1)
	    return notify_fail("你用尽了吃奶的力气，还是打不开这道门。\n");
	p->delete_temp("lilia_wind");
	tell_object(p, "当你的手刚摸到门把的时候，门忽然自动地打开，一阵狂风将你卷进门内!\n");
	p->move(AREA"eda0");
	p->receive_damage(5);
        return 1;
    }
    else 
	return notify_fail("你想开什麽？\n");
}    
