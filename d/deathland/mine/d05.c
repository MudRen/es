
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人矿坑的大洞穴");
  set_long(@Long
Long
,@CLong
一个很黑很暗的大洞穴,曾经是个含量丰富的矿坑.在这里的地上充满了黑色的
泡沫和一些骨骸. 在地上有一个水池(pool),里面传来一些优美的声音,似乎想吸引
你进去的样子.
CLong
);
set("c_item_desc",([
    "pool":"一个小小的水池,但似乎有生物居住的样子.\n",
//    "skeleton":" ",
//    "bubble":" ",
    ]) );
set("exits",([
             "east":Mine"/d04",
             ]));
reset();
}
void init()
{
   add_action("to_enter","enter");  

}

int to_enter(string str)
{
   if (!str || str!="pool") write("Enter what.\n"); 
   else {
     write("你进入了水池.\n");
     this_player()->move_player(Mine"/d06",({"%s enter the pool.\n","%s进入了水池",
       "%s enters from outside.\n","%s 从外面进来这里.\n"}),"");
     } 
   return 1;
}
