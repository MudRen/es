#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("林间小径");
       set_long( @Clong
在一道巨大的铁栅之後，是一条阴森森的林间小路，浓密的枝叶，把天光
完全的遮蔽起来，即使是晴天的正午，这里也是伸手不见五指。小径的底部，
积满了湿漉漉的落叶，彷佛从它们落到地面时，就再也没有乾过。树干的根部
长满了黑绿色的青苔，一些蜗牛在上面爬行，留下了闪亮的分泌液。据说梁山
泊好汉以前，常常到此打猎取乐，但最近，似乎发生了什麽事，大家都不敢再
来了。
Clong
          );
set("exits",([
               "south":TROOM"gate3",
              ]) );
create_door("south","north",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "一道厚重的铁栅",
             "c_name" : "铁栅",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int clean_up() { return 0; }