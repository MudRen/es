// Deathland/holyplace/h09.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","奇怪的地方");
  set_long(@Long
Long
,@CLong
一个奇怪的地方, 四处的黑影无声无息地向你侵袭而来. 四面都是岩石, 你似乎
是通过岩石来到这个地方. 你必须了解那边的岩壁是假的, 这样你才能离开这里.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h14",
             "east":Deathland"/holyplace/h22",
             ]));
set("exit_invisble",1);
reset();
}

