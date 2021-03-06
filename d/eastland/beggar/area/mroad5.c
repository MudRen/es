#include "../dony.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("田野");
    set_long( @C_LONG
你现在正走在一片青翠的田野上，四处绿草如茵，地上各色繁花。偶尔一阵清
风徐过，繁花如雨，五色缤纷，冉冉飞舞，似下不去；花随同飞舞，漫天花香泌人
心脾，犹还染濡衣襟，久久不能散去；有时徐风如一股清流，自上而下，全身无不
通畅。田野东南边是横亘无绵的群峰，邻近的是一面山壁，山壁下似乎有些足迹，
底部部份有个大洞 ( hole ) 。由此而北则是通往海威港。

C_LONG
);
                                
    set_outside( "haiwei" );
    set( "light", 1 );
    set( "exits", ([
           "north" : "/d/eastland/haiwei/mroad4" ]) );
    set( "objects",([
          "beetle1":DMONSTER"beetle",
          "beetle2":DMONSTER"beetle",
          "beetle3":DMONSTER"beetle",  
       ]) );
    set("c_item_desc",([
          "hole":@LONG
一个黑色的大洞，洞里杂草丛生，有些空间似乎能让你容身，
或许你可以挤进去(squeeze)。
LONG    
    ]) );
    reset();
}
void init()
{
   add_action("do_squeeze","squeeze");
}
int do_squeeze(string str)
{
   if ( !str || str!="hole" ) {
      write("你想要挤进那里去呢？是要挤进洞里 ( hole ) 吗？\n");
      return 1;   
   }
   tell_object(this_player(),@LONG
   
你把身子挤进山洞里，却意外地发现经过刚才的大洞原来内中别有天地，
竟然有一个村落在这里 ！ 
   
LONG 
   );  
   this_player()->move_player(DBEGGAR"cross",({
         "%s把身子挤进山壁底部的一个大洞里。\n",
         "%s从外面走了进来.\n"}),"");
   return 1;
}