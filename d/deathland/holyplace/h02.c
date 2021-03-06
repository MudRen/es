//Deathland/holyplace/h02.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","矮人圣地的祭坛");
  set_long(@Long
Long
,@CLong
在这里你能感觉到一种神圣且庄严的力量,四周柔和的亮光更使得这地方充满著祥
和的气氛,你目前的位置是在矮人圣地的祭坛.有四根很大的圆柱耸立与四个角落,中间
是一个大的祭坛,而有个巨大的神像矗立其中,明显的是矮人的神,Yang.另外,有著十二
团熊熊的烈火以一个圆形围绕著祭坛,然而你却不会觉得那些火的火光很刺眼,相反的
那些火有种柔和的感觉.南方有一个造形奇特的小屋,你\或\许\应该去看看.
CLong
);

set("c_item_desc",([
    "fire":"十二团熊熊的烈火.以一个圆形围绕著祭坛\n",
    "statue":"一座巨大的神像.\n",
    "altar":"一座空无一物的祭坛.\n"
    ]) );
set("exits",([
             "south":Deathland"/holyplace/h03",
             "west":Deathland"/holyplace/h05",
             "east":Deathland"/holyplace/r05",
             ]));

set("objects",([
    "guard":Monster"/guard08",
    ]) );
reset();

}
