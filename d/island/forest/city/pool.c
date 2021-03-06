#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("香津美泉");
    set_long(@LONG
这里有个聚集清净泉水的小水池，泉水自假山上涌出，形成一道小瀑布
流下，下头有个小斗勺，当水注满时，斗勺就会倾倒使水流入池中；水池中
一群鲤鱼悠闲的游著；迎著一阵阵的清风，倾听著斗勺一声声的敲著石头，
未尝不是一种情趣！
LONG
      );
      set("light",1);
      set("water_source",1);
      set_outside("island");
      set("exits",([
          "north":CITY"inway1"]) );
      reset();    
}

void init()
{
   add_action("do_drink","drink");
}   

int do_drink(string str)
{
   if( !str || str!="water")
      return notify_fail("你想喝什麽？\n");
   
   tell_object( this_player(),"你蹲下来喝了几口甜美的泉水...........\n");
   tell_room(environment(this_player()),
    this_player()->query("c_name")+"缓缓的蹲了下来，仔细的品□著池中的泉水！\n"
   ,this_player() );
   
   if( (string)this_player()->query("class") != "knight") 
       return notify_fail("你心想：唉，这水不过如此而已嘛！\n");
   tell_object(this_player(),"喝了泉水後，你的精神似乎好多了！\n");
   tell_room( environment(this_player() ),
      "突然间他举起双手，大叫一声～喵喵万岁～，你心想，这泉水有问题哦！\n"
      ,this_player() );
   this_player()->set("spell_points",(int)this_player()->query("max_sp") );
   return 1;
}  