#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("����С��");
	set_long(@Long
����С�����������������졣���߲�Զ���������ϵ����Ĺ㳡, �ϱ�
��һ��Сҩ�ݡ�����������һ�ξ�����Կ�������, �Ӷ��ų�ȥ����һƬ
������ԭҰ��
Long
);
	set("exits", ([
		"south"		: HERE"potion_shop",
		"east"		: HERE"tinker_way2",
		"west"		: HERE"square",
		]));
}
