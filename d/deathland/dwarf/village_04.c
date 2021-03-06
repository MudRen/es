
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The barrack","军营");
  set_long(@Long
Long
,@CLong
这里是军营的内部,有好几栋建筑物(buildings)在路的两旁,虽然这些建筑
物的外形看起来都一模一样,但是每一栋建筑物都有其特别的功\能.
有条小路穿越军营,连接著矮人的村落.
CLong
);

set("c_item_desc",([
    "buildings":"一些方方正正的建筑,每栋建筑的门上都有一块板子标示该建筑\n"
                "的功\能,其中有三栋建筑的功\能似乎比较有趣,分别是:\n"
                "新兵教育中心(new_trained_soldier center)\n"
                "巨人攻击模式研究室(the college of studing trolls' attack mode)\n" 
                "兵器库(weapons storage room)\n",
    "center":"新兵教育中心(new_trained_soldier center)\一处训练新兵的地方\n",
    "college":"巨人攻击模式研究室(the college of studing trolls' attack mode)\n"
              "一处研究巨人的攻击模式,期望能够击溃巨人的研究单位\n",
    "room":"兵器库(weapons storage room)"    
           "储存各式各样武器的地方 \n",    
                ]) ); 
set("exits",([
               "south":Deathland"/dwarf/village_03",
               "north":Deathland"/dwarf/village_05",
             ]));
::reset();
}

void init()
{
add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str) return 0;
   if (str=="center") {
    this_player()->move_player(Deathland"/dwarf/center",
        ({ 
        "%s进入了新兵训练中心.\n",
         "%s从外面走了进来.\n"}),"");
     return 1;
     }
   else if (str=="college") {
     this_player()->move_player(Deathland"/dwarf/college",
      ({
      "%s进入了巨人攻击模式研究室.\n",
      "%s从外面走了进来.\n"
       }),"");
     return 1;
     }
   else if (str=="room") {
     write("当你试著进入兵器库的时後,发现它被锁著.\n");
     return 1;
     
     }
   else if (str=="buildings" ||str=="building") {
     write("你想进入那一栋建筑物?\n");
     return 1;
     }
   else return 0;  
}
