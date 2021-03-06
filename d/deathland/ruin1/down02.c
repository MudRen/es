
// Deathland/ruin1/down02.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹地下室");
     set_long(@Long
Long
,@CLong
这里是遗迹的地下室 ,似乎是用来避难的地方 .然而地上到处是一堆堆的骨骸与乾
掉的血迹 .更让人觉得气氛显得十分的诡异 .你无法想像当时的情况是如何 ,但是你\或\
\许\可以理解到为甚麽这地方一直没有人发现它 ,因为当时的一场灾难把这座城市的人都
给毁灭了 .甚至於躲在这里的人都不能幸勉 .南边有一个石门 ,在门後似乎是储藏食物
与饮水的地方 ,但是你不能确定目前里面会有什麽东西 .
CLong
);
     set("exits",([
         "south":Deathland"/ruin1/down03",
         "north":Deathland"/ruin1/down01",
         ]) );
     create_door("south","north",([
             "name":"stone door",
             "c_name":"石门",
             "keyword":({"stone door","door",}),
             "c_desc":"石门",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

