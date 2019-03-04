
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","阴暗的虚无飘渺处");
  set_long(@Long
Long
,@CLong
一处阴暗的地下世界,四处的黑影无声无息地向你侵袭而来.这里的寂静令人感到害怕,
让你不自主的想要发出一些声音.没有风声,没有水声,甚至你无法听到自己的脚步声,你不
禁怀疑自己处在一个虚无的地方.幸好你发现你的东方有一道很明亮的光源在那里.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h07",
             "east":Deathland"/holyplace/h05",
             ]));
reset();
}
