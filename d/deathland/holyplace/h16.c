// Deathland/holyplace/h16.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);	
  set_short(" A strange place","阴暗的虚无飘渺处");
  set_long("need work .\n",
"一处阴暗的地下世界,四处的黑影无声无息地向你侵袭而来.这里的寂静令人感到害怕,\n"
"让你不自主的想要发出一些声音.没有风声,没有水声,甚至你无法听到自己的脚步声,你不\n"
"禁怀疑自己处在一个虚无的地方.你的视野越来越小,似乎你的眼睛被一些黑色的\"雾\"挡住\n"
"了视线.在这个危险的地方,你最好提高警觉,因为随时都有可能从黑暗中走出邪恶的生物.\n"
"这个地方似乎是个封闭的区域,北南西三个方向都是厚厚的岩壁,东边的唯一出口也窄窄的\n"
".而最奇怪的事,这地方似乎有著亮光(light).\n"
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    "light":"@@to_look_light",
    "plate":"@@to_look_plate",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h15",
             ]));
reset();
}

string to_look_fog()
{
     return "是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.\n"
            "\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.\n" ;
}

string to_look_light()
{
    return "那道微微的亮光似乎来自西边的岩璧上面,仔细一看,原来西边的岩壁上面.\n"
           "有一个平台(plate).\n";
}

string to_look_plate()
{
      return "一个小小的平台,但是由於地势太高,所以你无处法清楚地看清上面有甚麽东西.\n";
}
