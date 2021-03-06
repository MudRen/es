#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("东大街");
	set_long( @LONG
你走正走在「巫咸城」内东大街上，大街往南、北边方向延伸，可容纳三匹马
并行的宽度，而东边是东门。东大街的地是用大理石铺成的，整理的很乾净。自从
主大道封闭已後，东大街变成了城中最热闹的地方，原因无他，因为许多重要的铺
子都在这条东大街上。西边是一家客栈。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"eastgate",
       	    "west" : SCITY"wine1",
       	   "south" : SCITY"es",
       	   "north" : SCITY"en1"
        ]) );
        set( "objects", ([
           "visitor":SWMOB"visitor2"
        ]) );
	reset();
}
