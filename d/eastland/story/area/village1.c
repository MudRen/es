#include "../story.h"
inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("村口");
	set_long(@LONG
你来到了一处羽民族居住的村庄口上，两旁是一排排的小屋。由於这村落置身
在一大片树丛里，显得格外神秘又隐敝，好似一座天然的住处。另外在道路上种植
了许多葡萄树，树上的果实平时供羽民族食物，而果实中的液汁也是羽民族赖以为
生的水源。由於这村落没什麽活动的空间，小孩子们都会跑到西北边的草原去游玩
，但大人们都深以为忧，恐怕这里被人发现。
LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house1",
                "west" : SAREA"house2",
               "south" : SAREA"village2",
           "northeast" : SAREA"plain2",
        ]) );
        set("objects" , ([
           "guard#1" : SMOB"guard1",
           "guard#2" : SMOB"guard1",
        ]) );
	reset();
}
