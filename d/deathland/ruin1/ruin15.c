
// Deathland/ruin1/ruin15.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹");
     set_long(@Long
Long
,@CLong
一座破旧的遗迹 ,这里似乎已经荒废很久了 .地上到处是残砖破瓦 ,更让人觉得
这地方已经\许\久未曾有人烟了 .一种绿色的藓苔植物附在两旁的墙壁上 ,使得这地方
的气氛更显得十分的诡异 .这个地方是遗迹的西北角 ,你来到这个地方的时候 ,你的
视线就被一个雕刻很精致的一个小石像给吸引住了 ,彷佛那是一个栩栩如生的人伸出
手来想要与你握手寒喧的样子 .
CLong
);
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("exits",([
         "southeast":Deathland"/ruin1/ruin24",
         ]) );
     ::reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "一个栩栩如生的石像 ,这石像实在是不可多得的艺术品 ,它的样子就像是想\n"
          "要和你握手寒喧 ,让人有一种友善的感觉 ,你是否感受到它友善的气息而不\n"
          "禁地放下你的武器来与它握手呢 ?\n" :
          "???"
         );
   return 1;
}

void init()
{
   add_action("to_hand","hand");

}

int to_hand(string str)
{
    if (!str||str!="statue") return 0;
    if ( this_player()->query("weapon1") ) 
       write("你觉得并没有甚麽不同.\n");
    else { 
       write("当你手握住雕像的手时, 你觉得一种友善的感觉传入你的心中\n"
             "好像一种特别的声音回绕在你的耳边.\n...Ding Ding Ding....\n"
             "Ding Ding ......\n"
             );
       }
    return 1;        
}
