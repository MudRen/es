#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "stairway", "走廊" );
	set_long(
@LONG
你正漫步在井龙宫的走廊，一盏盏琉璃灯火悬在走廊的两旁，在这里你做什麽事
都得特别小心，否则会发生什麽事只有天知道。
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace7",
             "west" : OTEMP"palace3",
	     "east" : OTEMP"palace8",
	]) );
        create_door("north","south", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "钻石大门",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "一扇用整块钻石切割而成的门"
                    ]) );
         set("light",1);
         reset(); 
}
