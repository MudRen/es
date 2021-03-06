
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河边");
  set_long(@Long
Long
,@CLong
目前你位於一个奇怪的地方, 除了你来的方向外, 其馀的三个方向都是可怕的河水.
有一个告示牌(plaque)立於地上, 上面还有一个很大的号角(horn).
CLong
);

set("c_item_desc",([
    "river":"这些河流的流速非常非常的快, 除此之外你发现在河流的对岸似乎\n"
            "有个小岛.\n",
    "island":"一个位於河中的小岛, 上面似乎有著奇怪的植物存在著, 但你并不能\n"
             "确定, 因为距离实在是太远了.\n",        
    "horn"  :"一个很大的号角\n",
    "plaque":"假如你想通过死亡之河到达灰暗之岛的话,请吹(blow)号角.\n",      
           ]) );

set("exits",([
     "west":Deathland"/dwarf/river02",
     ]) );
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
    
    write("从遥远的对岸忽然飞来一条奇怪的触手, 把你整个人拉起来, 并且触手\n"
          "迅速的往後拉, 你整个人就这样越过了河面,来到了对岸.\n"
         );
    this_player()->move_player(Deathland"/island/i01",({
        "%s被一个奇怪的触手拉走了.\n","%s从空中掉了下来.\n"
        }),"");      
    return 1;     
}
