#include "goomay.h"

inherit ROOM;

int mark;
void create()
{
        ::create();
        set_short("奇异的房间");
        set_long( @LONG_DESCRIPTION
你现在正位於一个奇异的房间中，这里跟其他地方有显著的不同，
一点也不显得脏乱和燥热，家具和摆\设都十分恰当，靠墙的地方还有
一个小小的橱柜(closet)和镜台，一股股的凉风不知道从哪里吹来，
令人十分舒畅。
LONG_DESCRIPTION
        );

set("item_desc",([
    "closet":  "这是一个美丽的雕花橱柜，看起来只是个衣柜。\n" 
           ]) );
set("search_desc",([
     "closet":"@@to_search_closet",     
          ]) );

set("exits",([
     "east"	:  Goomay"cellar5",
     ]) );

 reset();
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#11");
}
void reset()
{
   ::reset();
   mark=0;
}

string to_search_closet()
{
   object ob1;
   switch(mark) {
   case 0:  
     mark=1;
     ob1=new(Obj"ingot");
     ob1->move(this_player());
     return "你仔细的翻箱倒柜，最後只发现了一面奇怪的破金牌。\n";
   case 1:
     return "在一阵仔细的搜索下，再也找不到有趣的东西了。\n"; 
   }  
}
