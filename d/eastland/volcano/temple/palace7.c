#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "小龙女寝宫" );
	set_long(
@LONG
这里是龙王的独生女－兰心的寝宫，房间中弥漫著一片淡淡的清香，鹅黄色
的被子，粉色的床，墙壁是淡淡的紫色，梳妆台上放了一些小饰品、一把梳
子和一只绣花针。
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace5",
	]) );
        create_door("south","north", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "钻石大门",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "一扇用整块钻石切割而成的门"
                    ]) );
         set("light",1);
         set("objects", ([
             "princess":OMONSTER"princess",
             ]) );
         reset(); 
}
