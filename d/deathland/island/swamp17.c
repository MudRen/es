
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之岛的沼泽");
  set_long(@Long
Long
,@CLong
一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心谨慎
你的每一步. 越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮住了. 这
地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经快深陷於沼泽里了.

CLong
);

set("exits",([
     "east":Deathland"/island/swamp21",
     "west":Deathland"/island/swamp13",
     "south":Deathland"/island/swamp18",
     ]) );
set("objects",([
    "hand":Monster"/beast04",
    ]) );
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exit_invisble",1);     

::reset();
}

string search_here()
{
     return "当你仔细寻找这里的时候, 你发现西南方沼泽的水面上似乎很奇怪,\n"
            "想想原来是上面竟然连一片树叶也没有, 你跟本无法通到那个地方\n"
            ". 似乎你必须寻找其它的方法才行.\n";
}
/*
int clean_up()
{
    return 0;
}
*/