#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("a small road","С·");
	set_long(@CLong
��վ��һ������С·��, С·���������˺�Щ��֪���Ĺ���������ũ
��������������, ż��Ʈ������\���̡�
CLong
);
	set("exits", ([
		"east"		: HERE"maple_street1",
		"west"		: HERE"small_road2"
		]));
}
