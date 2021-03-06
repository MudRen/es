#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

int be_knock=0;
void create()
{
    ::create();
    set_short( "山腰" );
    set_long(@C_LONG
你现在正走在一条山路上。路旁长满了一些不知名的白色花朵，闻起来有点淡
淡的香气。在花朵上有几只蝴蝶翩翩地飞舞著，尽情地吸吮著花蜜；花丛里还有蚱
蜢跳来跳去，一副不怕人的样子，路旁树上的鸟儿正呼朋引伴地高歌，似乎很快乐
的样子。或许，你该放下手边的工作，投入大自然的怀抱里，诚所谓「休息是为了
走更长的路」。在旁边有一颗树，树身上一条条的痕迹似乎是动物的爪子留下来的
。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "nwu","sd" }) );
    set( "exits", ([
     "southdown":LAKE"mountain8",
            "sd":LAKE"mountain8", 
     "northwestup":LAKE"mountain6",
            "nwu":LAKE"mountain6" 
    ]) );
    set( "c_item_desc", ([
      "tree" : @C_LONG
一棵斑白的树木，长得还算茂盛，树干周围是一条条的痕迹。树上有个不小的
洞，那似乎是动物的巢穴，或许你敲一敲(knock) ，说不定会有什麽从里面掉
下来也说不定。
C_LONG
    ]) );
    set("objects",([
     "cat#1":LMONSTER"cat",
     "cat#2":LMONSTER"cat",
    ]) );
    reset();
}
void init()
{
    add_action("do_knock","knock");
}
int do_knock(string arg)
{
   object ball;
   if ( present("wild cat",this_object()) ) return 0;
   if (!arg || arg!="tree") return 0;
   if ( be_knock ) return 0;
   tell_object(this_player(),"你用力地敲这颗树干，从上面的洞里掉下一颗珠子。\n");
   ball=new(LITEM"sea_ball");
   ball->move(this_object());      
   be_knock=1;
   call_out("back",300);
   return 1;
}
void back()
{
  be_knock=0;
} 
void reset()
{
   be_knock=0;
   ::reset();
}