#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the east gate", "����");
	set_long(@Long
�㿴��һ���Ͱ���Χǽ, ��һ�����š�һ������խ�ĵ�·�ɹ�����
����, ���������������Ұ�С�Χǽ������һ�����ŵĳ���, ����������
ʫ���ǳ�����ӽ���������硸������ά�ǡ���
Long
);
	set("exits", ([
		"east"		: "/d/erosmia/11,10.erosmia",
		"west"		: HERE"tinker_way1",
		]));
}
