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
�����ڷ����Ĵ����, ���Կ����˸�ʽ�������̵ꡣ����Ψһ��ð��
���ӻ���Ϳ��ڴ�����ߵ�һ�������С�
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street3",
		"north"		: HERE"square",
		"west"		: HERE"shop"
		]));
}
