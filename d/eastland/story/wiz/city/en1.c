#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("东大街");
	set_long( @LONG
你走正走在「巫咸城」内东大街上，大街往南边方向延伸，可容纳三匹马并行
的宽度，北边则是北大街。东大街的地是用大理石铺成的，整理的很乾净。自从主
大道封闭以後，东大街俨然变成了城中最热门的地带，原因无他，因为许多重要的
铺子都在这条东大街上，这里更尤於接近城中心道路，平时人潮携来我往，好不热
闹。西边是城中心道路可通往皇宫，东边则是一排排的商店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne1",
       	   "south" : SCITY"ee",
       	   "north" : SCITY"en2"
        ]) );
        set("objects", ([
               "vendor" : SWMOB"vendor1",
           "merchant#1" : SWMOB"merchant1",
           "merchant#2" : SWMOB"merchant2",
        ]) );
	reset();
}
