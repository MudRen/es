#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("����");
	set_long(
@CLong
�������õ��е�һ��, �������������Իص���������������һ�����ֵ�
С�ưɡ�
CLong
);
	set("exits", ([
		"west"		: HERE"bar",
		"north"		: HERE"tavern",
		]));
}
