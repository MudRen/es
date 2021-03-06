#include "ruin.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("巨岩上的平台");
	set_long(@CLong
眼前的景色让你大吃一惊, 你站在一块约数十公尺大的巨岩上, 下面是
一个广大的盆地。从这里俯瞰整个盆地, 底下一片翠绿。那下面全是树, 除
了树以外还是树, 有如一个广大的树海一般。在树海下面, 到底有什麽东西
隐藏著呢? 也许除了亲自下到盆地中探探以外, 也没有什麽别的办法了吧!
但是, 路呢? 想攀爬数十公尺高, 光秃秃的巨岩简直是拿自己的生命来开玩
笑!
    你的身後是原来的小径, 附近似乎是没有其他的出路了。
CLong
);
	set("exits",([ "back": FOREST"3n1w",]));
	reset();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg) 
{
	if( !arg || !(arg == "here" || arg == "plate") ) return 0;
	write( "巨岩边竟然有条往下的路! 若不是仔细看还看不出来呢!\n" );
   if( this_player() ) this_player()->set_explore("noden#16");
//	set("pre_exit_func", ([ "down":"go_down", ]) );
	add("exits",([ "down" : RUIN"hidden_path" ]) );
	add("exit_suppress", ({ "down", }) );
	return 1;
}

void reset()
{
	::reset();
	set("exits",([ "back": FOREST"3n1w",]));
}
