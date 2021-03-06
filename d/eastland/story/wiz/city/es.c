#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("东大街");
	set_long( @LONG
你走正走在「巫咸城」内东大街上，大街往北边方向延伸，可容纳三匹马并行
的宽度，南边则是南大街。东大街的地是用大理石铺成的，整理的很乾净。自从主
大道封闭已後，东大街变成了城中最热闹的地方，原因无他，因为许多重要的铺子
都在这条东大街上。这里两旁都是一排排的商店，在西边有一家可说是城内最大的
一间商店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	   "south" : SCITY"se",
       	   "north" : SCITY"ee",
            "west" : SCITY"store",
        ]) );
        set( "objects", ([
                "soothsayer":SWMOB"soothsayer1",
        ]) );
        reset();
}
