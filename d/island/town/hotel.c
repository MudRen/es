//#pragma save_binary

#include "../island.h"
#include <money.h>

inherit ROOM;
inherit SELLER;

void create()
{
    ::create();
    set_short("龙门客栈");
    set_long(@C_LONG
这是家新近成立的客栈，由於老板算准了这儿大有可为，故在此开了
家店。由於此处来来往往的商旅特别多，此处变成了龙蛇杂处之地。客栈
内充斥著掌柜的吆喝声及客人的喧闹声，但也有些人完全无视喧嚣，只是
安静的坐在角落的座位上独酌，看来此处确实是个是非之地。
C_LONG
             );
      set("exits",([
            "north" : ITOWN"town04"]) );
      set("light",1);
      set("no_monster",1);
      set_inventory( ({
                       ({ IOBJ"wheet", 20 , 20}),
                       ({ IOBJ"lu-wei", 15 , 15}),
                       
        }) );
        set( "objects",([ "lizardman" : "/d/island/hole/monster/valor",
                          "boss" : IMON"boss" ]) );
        reset();

}      
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_look","look");
  return;
} 
int do_search()
{
 tell_object(this_player(),"正当你在探头探脑的时候，柜台里的夥计跟你说道：『想买东西的话\n，看看价目表(list)就好了！』\n");
 return 1;  
}
int do_look(string arg)
{
  if (!arg || arg != "list") return 0; 
  show_menu();
  return 1;
}                     
 
void reset()
{
    room::reset();
    seller::reset();
}
              