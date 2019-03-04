#include "../story.h"

inherit ROOM;
int on_war=0;
void create()
{
        ::create();
	set_short("血瀑布");
	set_long( @LONG
这里就是传说中的血瀑布，笼罩在一团红雾里。在瀑布上流著得是鲜血，飞泻
而下犹如一抹红色的匹练，在昏暗毫无亮光之下，益发显得更加骇人。传说中，血
瀑布具有重生的能力，你只要把□体埋(bury)在这里，那□体就会有机会得到新的
生命，令人不可思议。
LONG
	);
	set( "exits", ([ 
       	      "crack" : SAREA"vhole2" 
        ]) );
	reset();
}
void init()
{
   add_action("do_bury","bury");
}
void resetwar()
{
    on_war=0;
}
void trigger()
{
   find_object_or_load(WMOB"war")->start_war();
}
int do_bury(string arg)
{
   object player,corpse;
   string name,pname;
   if ( !arg ) return notify_fail("你要埋什麽东西？\n");
   player=this_player();
   corpse=present(arg,player);
   if ( !corpse ) return notify_fail("你没有那样东西。\n");
   name=corpse->query("c_name");
   pname=player->query("c_name");
   if ( ( !corpse->query("chicorpse") ) || on_war ) {
      tell_object(player,sprintf("你把%s埋在血瀑布里却没发生任何事情。\n",name));      
      tell_room(this_object(),sprintf("%s把%s埋在血瀑布里却没发生任何事情。\n",pname,name),player);
      corpse->remove();
      return 1;           
   }
   corpse->remove();
   on_war=1;
   tell_object(player,sprintf("你埋在血瀑布里的%s突然发生了变化！\n\n",name));     
   tell_room(player,sprintf("%s理在血瀑布里的%s突然发生了变化！\n\n",pname,name),player);
   call_out("count1",5,name);
   return 1;
}
void count1(string name)
{
   tell_room(this_object(),set_color(sprintf(
     "忽然间，血瀑布里的%s活了过来！你心里闪过莫名的恐惧...\n\n",name),"HIR"));
   call_out("count2",10);
}
void count2() 
{  
   trigger();
}
