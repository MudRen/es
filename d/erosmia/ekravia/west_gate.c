#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short( "����" );
	set_long(@Long
�����ǰ�����ά�ǵ�����, ��·��������ɽ��, ����ͨ��ɽ�еı�ʯ
��ӡ���ͷ��������ƽ����С��ֵ���
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way5",
		"west"		: "/d/erosmia/9,10.erosmia",
		]));
}
