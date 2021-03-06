
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("direction","south");
  set_short("The Entrance of Drawf mine","矮人矿坑的入口");
  set_long(@Long
Long
,@CLong
自古至今矮人对於金子就有一种特殊的能力,他们偬是能够发掘任何藏在地
底深处的任一处金矿,所以金子对於矮人似乎没有多大的吸引力. 但是另一种矿
产,Mithril 矿,制造武器与防具不可或缺的金属,对於正处於战争状态的矮人们
来说,它就显得特别的重要了.这里是矮人矿坑的入口.这个矿坑提供矮人不可或
缺的金属 Mithril 和\许\多人梦寐以求的黄金.
在地上有铁轨铺设著.专供运矿车通行使用.你能看到\许\多运矿车来来往往.矮人
正辛勤地工作著.铁轨一直延伸到地底深处,通往未知的世界,而铁轨的另一端是
到东边的一座炼矿厂.
CLong
);
set("exits",([
//             "east":Deathland"/mine/factory",
             "north":Deathland"/city/c6",
             "south":Deathland"/mine/mine_02"
             ]));
#include <replace_room.h>
}
