#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("a farmer's house", "农家");
	set_long(@CLong
你走进一家农家, 看见门口的广场上几只鸭子正悠哉悠哉地闲晃著。
一个老人坐在门口, 安详地望著广场外的景色。
CLong
);
	set("exits", ([
		"south"		: HERE"small_road2"
		]));
	set( "objects", ([
		"oldman": MOB"old_man",
		"duck1"	: MOB"duck",
		"duck2"	: MOB"duck",
	]) );
	reset();
}
