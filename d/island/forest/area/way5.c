#include "../tsunami.h"
#include "move.h"



inherit ROOM;

int seed;

void create()
{
    ::create();
    set_short("枯\木");
    set_long(@LONG
这儿四周长满了奇形怪状的植物，大多是目前尚不为人知的。风也已经
和缓多了，不像狭道中那般强劲可怕；令人不解的是：为何这儿的植物都欣
欣向荣，唯独这棵十分巨大的树(tree)会枯萎掉了呢？
LONG
             );
    set("exits",([
            "south":AREA"way4"]) );
    set_outside("island");
    set("item_desc",(["tree":@ALONG
仔细的瞧一瞧这巨大的枯木，似乎和河边的那棵是相同品种的植物，只
是，为何河边那棵会长得那麽茂盛，而这棵却已经枯萎了呢？嗯......
难道传说中的守护灵－龙皇　就是这幅模样吗？
ALONG
              ]) );          
    reset();
}

void init()
{
    add_action("do_pray","pray");
}

void reset()
{
    ::reset();
    seed = 1;
}
int do_pray(string str,object obj)
{
     
     obj=new(TOBJ"seed");
    
     if( !str || str != "seed")
        return notify_fail("你努力的祈求著，希望枯木能冒出一颗种子给你..\n"); 
     if( !this_player()->query_temp("luoko_quest")) {
   write("你虔诚的祈祷了半天，结果只有一只乌鸦从你头上呱呱叫著飞过....:P\n");
       return 1;
       }      
     
     if( seed == 0){
     write(@ALONG
突然一阵光芒围绕著你，一位老态龙锺的男人出现在你的面前：
    孩子，真是不巧，已经有人在帮我了，不过还是谢谢你！
ALONG
       );
       return 1;
     }
       else{         
     write(@BLONG
突然一阵光芒围绕著你，一位老态龙锺的男人出现在你的面前：
　　孩子，你愿意帮我忙是吧？这是我的种子，也是我灵力的来源，请你将它种在
御花园中，让我重生，好让我有足够的灵力来保护这个民族；孩子，一切就都拜托
你了！
　　只见到一棵种子缓缓的飘到你手中，接著光芒就消失了.........
BLONG
          );
     obj->set("getter",(string)this_player()->query("name") );
     obj->move(this_player());
     tell_room(environment(),
     "突然一阵光芒拢罩著"+this_player()->query("c_name")+"，但不久就消失了！\n");
     this_player()->delete_temp("luoko_quest");
     seed = 0;
     this_player()->set_explore("island#4");
     return 1;
     }
}
