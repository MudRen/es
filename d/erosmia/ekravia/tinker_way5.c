#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("����С��");
	set_long(@Long
����С����������������, ���߲�Զ�����ǳ���������ˡ�С������
����ɽ��, ͨ�������ı�ʯ��ӡ�
·���˼�����, ���Եķ��ݴ��Ͱ�������, ����Խ�����෿��Խ�ߴ�
������������һ��·�Ϳ��Եִ�������������Ĺ㳡��
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way4",
		"west"		: HERE"west_gate",
		]));
}
