#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小径");
	set_long(@Long
你走在工匠小径上, 东边不远处就是这个城镇的中心广场。南边的街
上开了一家铁匠铺, 从里面不时有叮叮咚咚的敲打声传出来。
Long
);
	set("exits", ([
		"east"		: HERE"square",
		"west"		: HERE"tinker_way5",
		"south"		: HERE"smithery",
		]));
}
