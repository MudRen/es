// Deathland/holyplace/h09.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A very cold place","�����ĵط�");
  set_long(@Long
Long
,@CLong
һ���ǳ�����ĵط�, ��������ܲ���. 
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

