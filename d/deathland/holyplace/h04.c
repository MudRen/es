//Deathland/holyplace/h04.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","矮人圣地");
  set_long(@Long
Long
,@CLong
你目前处在一间魔法小屋内,四周的力场十分的强烈,似乎这里有著一种强大的魔力
.但是这个屋子空空荡荡的,除了房屋中间有一个奇怪的水晶球(crystalball),以及在水
晶球的旁边有一个标示(sign).
CLong
);

set("c_item_desc",([
    "sign":"警告:当你碰触(touch)这颗水晶球的时候,你将被传离这个神圣的地方.\n",
    "crystalball":"一颗魔法水晶球.\n",
    ]) );

set("exits",([
             "northeast":Deathland"/holyplace/r03",
             ]));
             

reset();
}

void init()
{
   add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str||str!="crystalball") return 0;
    
    write("当你碰到水晶球的一刹那,你整个人忽然腾空,然後到达了另一个地方.\n");
    
    this_player()->move_player(Deathland"/city/church",({
    "..\n","%s忽然整个人消失的无影无踪.\n","..\n","在一阵耀眼的强光下,%s出现在这个地方.\n"
    }),"");
    return 1;
}
