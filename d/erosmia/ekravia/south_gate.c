#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the south gate", "����");
	set_long(@Long
Long
,@CLong
����վ��һ�������������ڴ����ڹ��ӵ���ǽ����, ������ԼԼ��
������Զ��һ����ש��ɫ���󷿡���·�������������ȥ, ���Ѳ�������
Ұ�������С·, ����һ����Ⱦ��ʯ������
CLong
);
	set("exits", ([
		"south"		: "/d/erosmia/10,11.erosmia",
		"north"		: HERE"maple_street1",
		]));
}
