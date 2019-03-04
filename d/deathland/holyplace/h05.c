//Deathland/holyplace/h05.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set("no_monster",1);
  set_short(" Drawf holy place ","矮人圣地");
  set_long(@Long
Long
,@CLong
在这里你看到一些很大的建筑,而且四周充满著柔和的亮光,你目前位於矮人圣地.
在西边的通道上有一层魔法墙,似乎在防止一些可怕的生物入侵.从这里往东,你能到达
矮人祭坛,而西边则是一个未知的区域.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h06",
             "east":Deathland"/holyplace/h02",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();

}
