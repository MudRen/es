#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("����С��");
	set_long(@Long
�����ǹ���С��, ���߲�Զ�����ǳ���Ķ�����, ԶԶ�Ŀ���������
��Ĺ�����ԭҰ����С���������Ե������ϵ����Ĺ㳡, ��������������
����м���
Long
);
	set("exits", ([
		"east"		: HERE"east_gate",
		"west"		: HERE"tinker_way2",
		]));
}
