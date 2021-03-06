// Deathland/holyplace/h14.c
// Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

int search_slit;
void create()
{
	::create();
  set_short(" A strange place","阴暗的虚无飘渺处");
  set_long(@Long
Long
,@CLong
一处阴暗的地下世界,四处的黑影无声无息地向你侵袭而来.这里的寂静令人感到害怕,
让你不自主的想要发出一些声音.没有风声,没有水声,甚至你无法听到自己的脚步声,你不
禁怀疑自己处在一个虚无的地方.你的视野越来越小,似乎你的眼睛被一些黑色的\"雾\"挡住
了视线.你必须随时提防从黑暗中跑出的危险,那些黑暗的雾中很明显藏著邪恶的根源.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );

set("exits",([
             "north":Deathland"/holyplace/h10",
             "northwest":Deathland"/holyplace/h15",
             "south":Deathland"/holyplace/h09",
             ]));
set("pre_exit_func",([
    "south":"to_south",
    ]) );   

set("exit_suppress",({"south",}));    
    
reset();
}

void init()
{
   call_out("notice_exit",1,this_object(),this_player(),0);
}

string to_look_fog()
{
     return can_read_chinese() ?
            "是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.\n"
            "\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.这\n"
            "地方的\"雾\"似乎特别的大,\或\许\有一些东西并不是显而易见的.\n"
            "你必需让你的眼睛适应这个地方的环境.\n":
            "need work.\n"; 
}

void notice_exit(object ob1,object ob2,int depth)
{
  
     if (depth<10) {
       if (environment(ob2)==ob1) {
         if ( depth==0 )
           tell_object(ob2,
             "这地方似乎有些奇怪. 但你目前不太能了解那是什麽.\n"
             );
         if (depth==4)
           tell_object(ob2,
             "这地方一定有些不寻常, 待久一点也\许\会\有更多的发现.\n"
             );
         call_out("notice_exit",1,ob1,ob2,depth+1);
         }
       else return ;
       } 
     else    
     if (environment(ob2)==ob1)
     tell_object(ob2,
                 "由於你待在这里够久,你的眼睛已经逐渐地适应这个地方,\n"
                 "这时你发现在南方的一处岩壁竟然是假的.\n"
                 );
     ob2->set_temp("echo_holy",0x01);   
     return; 
}

int to_south()
{
    if ( (int)this_player()->query_temp("echo_holy") & 0x01  )    
      return 0;
    else {
      write("你想去撞壁吗?\n");
      return 1;
      }
            
}

