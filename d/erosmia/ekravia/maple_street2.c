#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","枫树大街");
	set_long(@Long
Long
,@CLong
这里是枫树大街, 周围相当地清静。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street1",
		"north"		: HERE"maple_street3",
		]));
}
