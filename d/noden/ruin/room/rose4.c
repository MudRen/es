// rose4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市大道");
    set_long(@C_LONG
这里是罗斯托丽城的城市大道，在你的南方是紧闭的城门。东边耸立著一
栋高大的建筑物 (building) ，还有一座圆形的广场 (square) 隔著道路与这
栋建筑物相望。令你纳闷的是，这里居然还有保持的如此完整的建筑，真是不
可思议。
C_LONG
    );
    set("exits", (["north" : AREA"rose5"]) );
    set("item_desc", ([
	"building" : @BUILDING
这栋美轮美奂的建筑充份显示出古魔族帝国的强大，华丽的雕刻、高耸的
门柱，透露著古代文明的高度发达。半开的正门前有著一块石碑，上面题著：
「吾神女王的恩赐，先人传承的累积  罗斯托丽大图书馆」。
BUILDING
,
	"square" : @SQUARE
广场的入口立著一个小石碑，上头写著：「波塔祭坛，闲杂人等进入者处
死......大祭司米达尔奉旨公告周知」。
SQUARE
	]) );
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string str)
{
    if (str == "building" || str == "library")
	this_player()->move_player(AREA"lib0", "SNEAK", "");
    else if (str == "square" || str == "altar")
	this_player()->move_player(AREA"altar", "SNEAK", "");
    else
	return notify_fail("你想进入哪里?\n");

    return 1;
}
	

