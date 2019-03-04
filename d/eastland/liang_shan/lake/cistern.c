#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
        set_short( "水缸之中" );
	set_long(@C_LONG
这里是水缸里面，大小刚好够你把整个身子埋进水里，或许是因为这儿没几个
人来过，你发现缸中的鱼儿正好奇的打量著你。
C_LONG
	);
	set( "exits", ([
	     "out" : TROOM"room2"
	]) );
        set( "objects",([
             "fish1" : TMONSTER"fish11",
             "fish2" : TMONSTER"fish11",
             "fish3" : TMONSTER"fish11"]));
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



