
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("桥下");
  set_long(@CLong
这里是竹桥的正下方，有几截木头靠在河岸边，互相撞击著．从网子 (net)
上可以明显的看出它磨损的很厉害，有几个工人正忙著把一袋袋的东西装在板车
上，由车痕可看出这些货物很重．水是东向西流的，不知道河 (river)上游的情
形如何？
CLong
);
   

set("exits",([
             "up" :ZROOM"/bridge"    ]));
set("item_desc",([
	"net" : "一个不可能拿来捕鱼的网子，它的网眼实在太大了．\n",
	"river" : "一条湍急的河流．\n"
	]));
		             
set("objects",([
             "Dun gin" : ZMOB"/Dun_gin"  ]));
reset();
 }
void init()
 {
 add_action("do_swim","swim");
 }
 int do_swim(string str)
 {    int sk;
      sk=(int)this_player()->query_skill("swimming");
      if(random(sk) < 30 ) {
      write("\n你一招鱼跃龙门向水里射去,却抵不住河流的猛劲,被冲回来了\n");
      tell_room(environment(this_player()),(
             this_player()->query("c_name")+"以美妙的姿势跳进河里,却狼狈的从网子下爬了出来\n"),
             this_player() );
         return 1;
          }
      else{
      write("\n你努力地抓住出水口处的石头，看了一看，突然一根木头向你打来，\n"
            "\n想必是哪位巫师在开玩笑！游进去不被乱棒打死才怪\n");
      tell_room(environment(this_player()),(
              this_player()->query("c_name")+"以美妙的姿势跳入河里，却失望地爬了起来\n"),
              this_player() );
         return 1;}
 }          