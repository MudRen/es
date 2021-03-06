// g2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("破败的小庙");
    set_long(@C_LONG
荒芜的草丛里，有一间破败的小庙，里头似乎有个神龛 (niche)。
一片荒烟蔓草中，似乎有著条小路通往北方和西方。来到这里，你觉得
四周的空气似乎凝结著，彷佛是某种不祥的预兆。
C_LONG
    );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
这是一个由大理石所雕制而成的神龛，神龛的前方有个小牌子，上面写
著：「迷途的羔羊啊! 对万能的东方故事诸神虔诚地祈祷吧! 」。
NICHE
	]) );
    set("exits", ([
	"north" : AREA"g3",
	"west" : AREA"g1"
	]) );
    set("objects", (["ghost" : MOB"ghost"]));
    reset();
}

void init()
{
    add_action("to_pray", "pray");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下来祈祷，祈祷些什麽好呢? ...\n");
    p->move(AREA"rose4");
    return 1;
}
