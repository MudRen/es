
#include "../echobomber.h"

inherit Deathland+"/dwarf/daemon/muse";
inherit ROOM;

void create()
{
	::create();
    set("light",1);
    set_short("Muse Fountain","谬思泉");
    set_long(@Long
Long
,@CLong
你能够清楚的感觉到一种神圣的力量围绕於泉水的四周, 那就是传说中的谬思泉了.
关於谬思泉的传说实在太多了, 而它目前就在你的面前. 在这个宁静的地方你可以暂时抛
开俗世的烦恼, 静静地享受这个地方所给你的舒适的感觉. 
CLong
    );
   set("muse_color",7);
   set("item_func",([
       "fountain":"look_fountain",
       "muse":"look_fountain",
       ]) );
   
   set("exits",([
       "southeast":Deathland"/dwarf/muse51",
       ]) );
   reset();
}

void init()
{
     add_action("to_drink","drink");
     add_action("to_fill","fill");
}

int to_fill(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
    return fill_muse_water(this_player(),query("muse_color"));          

}

int to_drink(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
      write(
      "你确定要喝下这泉水吗??这泉水你完完全全不知道它的性质与成份....\n"
      "但是如果你已经了解它的特性的话, 就喝吧! 否则没有人会保证有甚麽\n"
      "事情会发生.\n"
      "用 < drink <color>_muse_water > 去喝下这泉水吧!!\n"
      );
    else if (str=="black_muse_water")  {
       drink_muse( query("muse_color") , this_player() );
       
       }
    else return 0;
    return 1;   
}

int look_fountain()
{ 
    write("一座与一般的泉水没有两样的谬思泉, 也\许\是这个地方给你的感觉, 也\许\是\n"
          "一股神圣的力量从泉水中散发而出, 你能确定这个地方就是谬思泉. \n"
          "这泉水看起来清凉洁净, 只是它的颜色是一种诡异的黑(black)色.........\n"
          );
    
    return 1;
}

