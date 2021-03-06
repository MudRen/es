
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("beach of GreyIsland","灰暗之岛的沙洲");
  set_long(@Long
Long
,@CLong
在这个地方你能看到一个很奇怪的现像, 除了险恶的河流之外, 正东边是一个可
怕的沼泽, 而东南方是一个黑暗的森林, 而东北方有一条小径, 通往北方的山岳. 这
里刚好就是所有地形的交会处.
地面上有一个告示牌(plaque), 上面还有一个很大的号角(horn). 旁边有一颗巨大的
植物, 它的上面布满了触手.
CLong
);

set("c_item_desc",([
    "river":"这河流的流速非常非常的快.\n",
    "horn" :"一个很大的号角\n",
    "plaque":"假如你想通过死亡之河回到原来的地方,请吹(blow)号角.\n",      
    "plant":"一颗很奇怪的植物.\n",      
           ]) );

set("exits",([
     "east":Deathland"/island/swamp01",
     "northeast":Deathland"/island/mountain01",
     "southeast":Deathland"/island/forest01",
     ]) );
set("no_monster",1);
::reset();
}

void init()
{
   add_action("to_swim","swim");
   add_action("to_blow","blow");
}


int to_swim()
{
    write("这河水流动的太快速了,即使你的游泳技巧再好,假如你真的下河去的话,\n"
          "你将直接游到阎罗王的面前报到了.\n");
    return 1;      
} 
int to_blow(string str)
{
    if (!str|| str!="horn") return 0;
    
    write("一条奇怪的触手, 把你整个人拉起来, 并且触手迅速的往前弹, 你\n"
          "整个人就这样越过了河面,回到了对岸.\n"
         );
    this_player()->move_player(Deathland"/dwarf/river03",({
        "","%s被一个奇怪的触手弹走了.\n","","%s从空中掉了下来.\n"
        }),"");      
    this_player()->set_explore("deathland#23");
    return 1;     
}
