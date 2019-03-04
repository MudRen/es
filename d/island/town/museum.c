#include "../island.h"

inherit ROOM;

void create()
{
	::create();
	set_short("和平纪念堂");
	set_long(@C_LONG
这儿就是和平纪念堂的一楼，中间伫立的石碑就是著名的『停战纪念
碑』。这个碑的形状有点像是一把长柄武器，插在这里的意义代表著「干
戈止於此地」。二楼是管理中心，还有史迹陈列室。
C_LONG
		);
	set("light",1);
	set("exits",([
                 "east" : ITOWN"square07",
                 "west" : ITOWN"square03",
               "south"  : ITOWN"square05",
               "north"  : ITOWN"square01",
                 "up"   : ITOWN"museum01"
            ]) );
        set("objects",([
                 "stone":IOBJ"stone"
                 ]));      
	reset();
}
