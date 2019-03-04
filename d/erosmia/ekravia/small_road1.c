#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("a small road","小路");
	set_long(@CLong
你站在一条泥土小路上, 小路两旁种满了好些不知名的果树。几间农
家隐藏在树荫下, 偶而飘出几许\炊烟。
CLong
);
	set("exits", ([
		"east"		: HERE"maple_street1",
		"west"		: HERE"small_road2"
		]));
}
