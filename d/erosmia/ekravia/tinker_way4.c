#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("����С��");
	set_long(@Long
�����ڹ���С����, ���߲�Զ�����������������Ĺ㳡���ϱߵĽ�
�Ͽ���һ��������, �����治ʱ�ж������˵��ô�����������
Long
);
	set("exits", ([
		"east"		: HERE"square",
		"west"		: HERE"tinker_way5",
		"south"		: HERE"smithery",
		]));
}
