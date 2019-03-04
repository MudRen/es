#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「巫咸国」东门");
	set_long( @LONG
这里是「巫咸国」的东门，城门两旁耸立著高墙，墙底则是布满青苔的基石，
另外在城楼上还刻著「巫咸国」三个漆金大字。城墙上，卫兵轮流交替，个个雄纠
纠气昂昂，威武挺拔，正在捍卫著「巫咸国」的安全。由这里往西则进入城中。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ee",
            "east" : SCITY"plain1",
        ]) );
        set("objects", ([
            "guard#1" : SWMOB"wiz_guard1",
            "guard#2" : SWMOB"wiz_guard1",
        ]) );
	reset();
}
