#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "王宫入口" );
	set_long(@LONG
你现在的位置是蜥蜴人王宫的入口，不过怎麽看都不像是个达官
贵人的栖息场所，倒不如说是个洞穴更为恰当；或许这是因为蜥蜴人
天生就比较不讲究居住环境所造成的。这两个卫兵似乎正因为你的到
来而提高戒备。
LONG
	);
	set( "exits",([
			"up" : HOLE"hole34",
			"southeast" : HOLE"hole36",
			]) );
	set( "objects",([
			"lifeguard#1" : HMONSTER"life_guard",
			"lifeguard#2" : HMONSTER"life_guard"
			]) );
	reset();
#include <replace_room.h>
}
