#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("八音涧");
        set_long( 
@LONG
沿著古木小径寻著泉水声音走到这儿，抬头一望，是条南北走向的山涧，一缕
飞瀑凌空而降，宛如一道丈来宽的匹练，银光闪闪，横卷直泻，注入了山涧之中；
瀑布和泉声相和，盘回跌落，如奏宫商，不绝於耳。忽而水流涓涓，轻声泠泠似丝
竹轻弹；忽而水声浩浩如同金石交鸣。每当降雨之日，八音涧上有灵雨飘空，银花
四射，飞舞而下；下有珠飞玉滚，翠浪奔腾，端的是上天造物之惊奇，令人赞叹。
LONG);
    set( "light",1);
    set( "exit_suppress", ({
          "west" }) );
    set("exits",([
          "west":LAKE"village4",
    ]) );
    set("objects",([
       "hermit":LMONSTER"hermit"
    ]) );
    ::reset();
}

void init()
{
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
        "这里没有什麽东西，不过你可以试著往池子(pool)潜潜(dive)看。\n");
   return 1;
}
int do_dive_down(string arg)
{
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="pool") {
    tell_object(player,"你想潜到哪里去。\n");
    return 1;
  }
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"你深吸一口气，以狗爬式潜下八音涧飞瀑下的水潭.......\n");
  tell_room(env,sprintf(
    "%s深吸一口气，以狗爬式潜下八音涧飞瀑下的水潭.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"你不暗水性，狼狈地爬了上来跑到「月到风来亭」小憩。\n\n");
  tell_room(env,sprintf(
    "%s狼狈地爬了上来，什麽收获也没有跑到「月到风来亭」小憩。\n\n",name),player); 
  player->move_player(LAKE"village6","SNEAK");
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   tell_object(player,"\n鹜地！水潭里一股吸力把你卷向一个地方....\n\n\n\n");
   player->move(LAKE"village7","SNEAK");
}  



