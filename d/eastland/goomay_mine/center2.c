
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("矿坑大厅");
  set_long(@CLong
这是座十分宽阔的地方，有\许\多的矮凳子，可见此地是矿工们休息的地方，
而整个房间被开凿成八卦型，宛如蜘蛛网的中心点，是控制矿坑内各出口的重要
枢纽，要到达矿坑的任何角落，都必须经过此地．
CLong
);
   

set("exits",([
             "west":ZROOM"/center1",
             "north":ZROOM"/center3",
             "southeast":ZROOM"/mine12",
             ]));

reset();
}
void init(){
add_action("south_wall","push");
      }
int south_wall(string ob)
{     

string him;
      him =(string)this_player()->query("c_name"); 
      if(!ob||ob !="south wall") 
      { write("你使尽了吃奶的力气，可是它一动也不动!\n");
        tell_room(environment(this_player()),(
        "你发觉"+him+"很努力地往墙壁撞去，你怀疑他的脑袋是不是装草的！\n"),
        this_player());
      return 1;      
        }
      else
      {
      
      write("\n你用力往墙壁一推，突然整个身子陷入墙里.\n");
      tell_room(environment(this_player()),(
      him+"突然从墙边消失了！\n"),
      this_player());
      this_player()->move_player(ZROOM"/control.c","SNEAK");
      } 
      return 1;
 }