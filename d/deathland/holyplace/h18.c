// Deathland/holyplace/h18.c 
// Created by Echobomber @Eastern.Stories 
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
禁怀疑自己处在一个虚无的地方.你的视野越来越小,似乎你的眼睛被一些黑色的\"雾\"挡住
了视线.在这个危险的地方,你最好提高警觉,因为随时都有可能从黑暗中走出邪恶的生物.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "southwest":Deathland"/holyplace/h19",
             "northeast":Deathland"/holyplace/h17",
             ]));
set("pre_exit_func",([
             "southwest":"to_in",
             ]) );
reset();
}

string to_look_fog()
{
     return can_read_chinese() ?
            "是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.\n"
            "\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.这\n" 
            "个地方的雾是越来越大了,你的视线也越来越模糊了.\n" :
            "need work.\n"; 
}

int to_in()
{
    write("你发觉你的方向感似乎有点不大对劲了.\n");
    return 0;
}
