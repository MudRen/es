// Deathland/holyplace/h09.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A very cold place","极寒的地方");
  set_long(@Long
Long
,@CLong
一个非常寒冷的地方, 冷的让人受不了. 
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h09",
             ]));
set("objects",([
    "beast":Monster"/beast05",
    ]) );
reset();

}

