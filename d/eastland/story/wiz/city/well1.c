#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("井底");
	set_long( @LONG
这里是一口枯井底。这口井因为年久以来水源已断，不堪使用，上面阳光照射
不到，以致於墙壁多生青苔，底部是一堆烂泥。好在还留有以前人家使用的连接水
桶的绳子，你可以试著往上爬去。
LONG
	);
	set( "exits", ([ 
           "up" : SCITY"wn2"
        ]) );
        set( "objects", ([
          "objects":SWMOB"dog1"
        ]) );
	reset();
}
