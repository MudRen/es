#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("玉石小径");
	set_long( @LONG
玉石小径延伸逾数十里长，通体红玉铺成，质若明晶，两旁均是参天花树，因
为树大枝繁，上面花枝纠结连成一片，一眼望去，直似两条花龙锦城，蜿蜓飞舞。
近距离狎玩，花树翠干银枝，琼花玉叶，□紫嫣红，萦青俪白，其大如斗，竞吐芳
菲。东北边是条白玉回廊。

LONG
	);
        set("light",1);
        set("exits" , ([
                "north" : SPALACE"garden1",
           "southeast" : SPALACE"garden4",
        ]) );
	reset();
}
