#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside","dgnisld") ;
	set_short( "cellar",  "地洞" );
	set_long(
	    "A mired swamp, You feel watery here. You can see a broad area\n"
	"of swamp. There is a hole on the ground, and a mired atair to down.\n"
	"The feeling here is very bad.\n",
            "泥泞的沼泽，十分泥泞，你感觉到这是一片很大的湿地，小心别陷入泥\n"
        " 沼，那将会要你的命的。地上有一个往下的楼梯，不过它是用泥巴做的。\n"
        );
               
        set( "exits", ([  "down" : DGNISLD"swamp5-5",  ]) );
        set( "objects", ([ "mire hand 3" : DGNISLD"monster/mhand.c", ]) );
        reset();
}
