#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","�������");
	set_long(@Long
Long
,@CLong
������һ�������, ���Ը�����һ�ŷ�������Ƭ��ɫ�ķ�Ҷ��ʱ����
����ǰƮ��, ����һ�����������ϲ�û�ж����˼�, ���ܴ��Ҳ�ǵͰ�
��ƽ��, ʹ�����Եø�����񾲡�
    ������һ��С·, ��ϸ����, �ƺ���Щ����Ѽ���е��������Ǳߴ���
CLong
);
	set("exits", ([
		"south"		: HERE"south_gate",
		"north"		: HERE"maple_street2",
		"west"		: HERE"small_road1"
		]));
}
