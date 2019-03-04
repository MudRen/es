
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河边");
  set_long(@Long
Long
,@CLong
一处奇异的地方, 到处是你未曾见过的植物, 潮湿的地表以及令人掩鼻的气味是这个
地方给你的感觉. 南面是一条流速极快的河川, 往北边走应是一个蝙蝠洞, 除此之外你也
可以沿著河流行走.
CLong
);

set("c_item_desc",([
    "river":"一条流速极快的河川.\n",
           ]) );

set("exits",([
     "north":Deathland"/dwarf/batcave01",
     "east":Deathland"/dwarf/river02",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    int swim;
    swim=this_player()->query_skill("swimming");
    if ( swim<50 )
      write("这河水流动的太快速了,假如你真的下河去的话,\或\许\你可以直接游\n"
            "到阎罗王的面前.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/well05",({
      "%s swims river.\n","%s跳进了河中并努力地往对岸游.\n",
      "%s appears from river.\n","%s从河中游上岸来.\n"}),"");
      write("你辛苦地游到了对岸.\n"); 
      }
    return 1;      
} 
