#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的内部");
  set_long(@Long
Long
,@CLong
这里是摩天塔的内部第一层的东南角, 这塔似乎是年久失修, 到处可见破碎的瓦
片与石块, 还有著一些奇奇怪怪的足迹印在地上. 这地方由於终年不见阳光, 显得十
分的阴暗潮湿. 
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/35",
               "south":Megatower"/floor1/44",
             ]));

::reset();
}
