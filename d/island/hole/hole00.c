#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "地下洞穴" );
	set_long(@LONG
一个黑漆漆的地下洞穴，阵阵的冷风由四面八方吹来，令你不停
的颤抖；然而当你静静地聆听时，好像还有潺潺的水声夹在风声之中
。黑暗之中，你隐约觉得似乎有双贪婪的眼睛正在打量著你。你不得
不提高戒心，以免随时有猛兽从洞穴跑出来。
LONG
		);
	set( "exits",([
			"up" : "/d/island/7,12.island.c",
			"north" : HOLE"hole01",
			"south" : HOLE"hole03",
		]) );
	reset();
#include <replace_room.h>	
}
