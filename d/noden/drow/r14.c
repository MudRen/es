#include "iigima.h"
inherit ROOM;

void create()
{
        ::create();
        set_short( "pool","小水池");
        set_long(
@C_LONG
这是一个清净的小水池，黑暗精灵村没有水井，所有的饮用水，
都是由这口小水池所供应，因为这里是自然涌出的矿泉，而又不受到
外来生物的干扰，看到清澈的泉水，令你不禁口渴了起来！
C_LONG
        );

        set( "light",0 );
        set( "water_source",1 );
        set( "exits", ([
                     "east":  DROW"r15",
        ]) );
        set("objects", ([
                "child#1": DRO"child",
                "child#2": DRO"child",
        ]) );
        set("c_item_desc",(["pool":
@C_LONG
这个甘泉是黑暗精灵村的唯一水井，你看了看，好像很深的样子。
C_LONG
           ]));         
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

   tell_object( this_player(),"你迫不及待的赶快喝几口甜美的泉水....\n");
   tell_room(environment(this_player()),
    
this_player()->query("c_name")+"像条小狗似的趴下去喝水！\n"
   ,this_player() );

   if( (string)this_player()->query("class") != "knight")
       return notify_fail("你喝了几口，感觉口角有种霉味！呃～\n");
   tell_object(this_player(),"喝了泉水後，你的精神似乎震奋了不少！\n");
   tell_room( environment(this_player() ),
      "他喝完水，拍拍身上的灰尘，站了起来！\n"
      ,this_player() );
   return 1;
}
