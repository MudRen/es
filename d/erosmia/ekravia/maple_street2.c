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
�����Ƿ������, ��Χ�൱���徲��
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street1",
		"north"		: HERE"maple_street3",
		]));
}
