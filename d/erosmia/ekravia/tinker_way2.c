#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("����С��");
	set_long(@Long
�����ڹ���С����, ������һ���������ص�ħ���ݡ����治֪�ڷ���
��ʲ����ֵ���Ʒ��
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way1",
		"west"		: HERE"tinker_way3",
		"north"		: HERE"magic_shop",
		]));
}
