
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The serect room","隐密的小房间");
    set_long(@Long
Long
,@CLong
你目前位於一个隐密的小房间里,这里充满诡异的气氛,似乎这里有著一股奇异的力量.
西边的墙上有著一个按钮(button),没有人知道按下去的後果会如何?
CLong
    );
    set("c_item_desc",([
        "button":"一个鲜红色的按钮,似乎提醒人们不要去碰它.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/v24",
             ]));
    set("objects",([
        "guardian":Monster"/guard06.c",
                   ]) );
    create_door("up","down",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一个小小的木门",
               "c_name":"小木门",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}

void init()
{
   add_action("do_push","push");
}

int do_push(string str)
{
   if (!str||str!="button") return 0;
   if (!present("guardian"))
      {
       write("一道强光笔直地穿过你的身体.\n\n\n\n"
             "你的灵魂离开了你的身体\n");
       this_player()->set_temp("block_command",1);
       
       call_out("recover",15,this_player());        
       say("当"+this_player()->query("short")+"按下了按钮後,一道强光刺穿了他的身体.\n"
           "然後"+this_player()->query("short")+"就倒地不起了.\n");       
       return 1;
      }
   else 
      {
      write("守卫说:不要碰那个按钮.\n");
      say(this_player()->query("short")+"试著按下按钮但被守卫阻止\.n");
      return 1;   
      }
}

int recover(object who)
{
   who->set_temp("block_command",0);
   tell_object(who,"慢慢地,你的灵魂已经回到你的身体之中.\n"
                   "而且似乎一种特别的力量注入你的身体里面.\n"
                   );
   who->set_explore( "deathland#25" );
   who->set_temp("deathland_magicwall",1);                
   return 1;
}
