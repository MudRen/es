#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "湿地" );
	set_long(@LONG
在这个巨大岩盘之下，竟然是一片十分潮湿的苔地，沼气弥漫，
呛得几乎都不能呼吸了。洞穴两旁的青苔也因为缺乏阳光的照射，而
呈现苍白的颜色，不禁令人怀疑：这里真的能住人吗？
LONG
	);
	set( "exits",([
			"east" : HOLE"hole33",
			"northwest" : HOLE"hole31"
			]) );
	reset();
#include <replace_room.h>
}
