
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the small pool","小水池");
  set_long(@Long
Long
,@CLong
一个小小的水池,然而却堆积满了骨骸,这里应该存在著一个很强的怪物.
CLong
);
set("item_func",([
    "skeleton":"look_skeleton",
    ]) );
set("exits",([
             "out":Mine"/d05",
             ]));
set("objects",([
    "siren":Monster"/siren",
    ]) );
reset();
}

int look_skeleton()
{
    write("一堆骨骸,似乎有被啃过的痕迹\n");
    this_player()->set_explore("deathland#6");
    return 1;
}