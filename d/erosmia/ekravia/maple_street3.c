#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","�������");
	set_long(@CLong
�����ڴ����, ������������, �൱���֡��ֵ����Ը�\����Ư������
��ʽ��, ¥�¿��˸�ʽ�������̵ꡣ·�Ի�����\��С���������մ�����
�����������߲ˡ�
    ����ʫ��֮�Ҿ��ڴ�ֶ���, ���������ĺ��֮�䡣������������һ
�ҹ��ϵ��õ� (tavern), ͬʱҲ��������õľưɡ�
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street2",
		"north"		: HERE"maple_street4",
		"west"		: HERE"tavern",
//		"east"		: HERE"bard_guild",
		]));
}
