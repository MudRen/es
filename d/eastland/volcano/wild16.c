#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long(
@LONG_DESCRIPTION
这片空地崎岖不平，到处都是黑色的石头，深褐色的土壤，你一看到这地型地物
就知道一定是火山爆发後的残留物，而且你也觉的这里蛮热的，你猜一定有火山在这
附近。你发现不远的前方有个城郭似的建筑，还有个吊桥，桥旁似乎还有人的样子，
你想那可能就是可怕的矮灵族部落，但好奇心却驱使你想过去瞧瞧。
LONG_DESCRIPTION
	);
set( "exits", ([
     "near" : OGROUP"warea1",
     "north" : ONEW"wild17",
     "southwest" : ONEW"wild13",
     ]) );
set( "pre_exit_func", ([
     "near":"to_near" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

int to_near()
{
  write("你向吊桥走了过去。\n");
  return 0;
}
