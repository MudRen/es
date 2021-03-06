#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("火山山脚下");
	set_long( 
@LONG_DESCRIPTION
你站在一座巨大的火山山脚下，那耸立云霄的火山山口似忽还会有阵阵浓烟
冒出，不知何时还会再爆发，你觉的这里非常的热，不可能有生物能在这里生存
下去，这里到处都是火山岩和浮石，这座由火山岩所构成的火山(volcano)，由於
到处是巨大的裂缝，因此想到达山顶是相当困难的。
LONG_DESCRIPTION
	);

set("item_desc",([
    "volcano" : "这座火山非常的高，以你的能力可能无法爬上去。\n",
       ]));
set( "exits", ([
     "south" : ONEW"wild20",
     "southwest" : ONEW"wild17",
     ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_climb","climb");
}

int do_climb()
{  if( random( (int)this_player()->query_skill("climbing") ) < 50 ) {
      write( 
         "想爬上去，门儿都没有!\n");
      return 1;
    };
    write(
          "你使出吃奶的力气终於爬了上去。\n");
    this_player()->move_player( ONEW"varea2.c","SNEAK" );
    return 1;
}
