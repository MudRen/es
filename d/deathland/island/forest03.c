
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest of GreyIsland","灰暗之岛的森林");
  set_long(@Long
Long
,@CLong
一个黑漆漆的森林, 这森林似乎充满著荆棘与矮灌木, 地上都是腐烂的树叶, 是
个令人很想逃离的地方. 你发觉你已在森林的深处了. 
CLong
);

set("search_desc",([
    "here":"@@search_here",
    ]));
set("exits",([
     "west" :Deathland"/island/forest02",
     "south":Deathland"/island/forest04",
     "east" :Deathland"/island/forest06",
     ]) );
set("exit_suppress",({"south","north",}) );
 ::reset();
}

string search_here()
{
   this_player()->set_explore("deathland#22");
   return "当你仔细地寻找这里的时候, 发现一条小小的通道往南沿伸.\n";
}