#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小径");
	set_long(@Long
工匠小径往东西方向延伸, 西边不远处就是城镇的西门了。小径往西
爬上山丘, 通往著名的宝石矿坑。
路上人迹不多, 两旁的房屋大多低矮而朴素, 不过越往东侧房屋越高大。
从这里往东走一段路就可以抵达镇上最繁华的中心广场。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way4",
		"west"		: HERE"west_gate",
		]));
}
