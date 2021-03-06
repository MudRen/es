#include "/d/eastland/legend/legend.h"

inherit ROOM;
inherit LAKE"in_swamp";
int be_search,be_dig;

void create()
{
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
啊！毒气，糟糕，你走进了最危险的沼泽地，四周都是足以致命的瘴气。但是
奇怪的是，这里不像其他沼泽地充满各式各样吃人的巨型怪物，也没有人类的□骨
，相反的，这里到处都是巨型沼泽怪兽的残骸；虽然你已经站在这里好一段时间，
但却没有任何一只怪物追来。你四下搜寻，发现的空气中弥漫著一股浓厚的血腥恶
臭，这股恶臭比沼气更刺鼻，更难闻，而且每隔一段时间就传来一阵怪啸，声音有
如牛哞，但却远比其响亮。你想，一定是更恐怖的怪物。
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south","down"}) );
    set("exits",([
            "east":LAKE"swamp7",
           "north":LAKE"swamp7",
            "west":LAKE"swamp7",
           "south":LAKE"swamp8",
            "down":LAKE"swamp_d1"
    ]) );
    be_search=0;
    be_dig=0;
    reset();
}
void init()
{ 
    ::init();
    add_action("do_search","search");
    add_action("do_shake","shake");
}
int do_search(string arg)
{
    if ( be_search ) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    tell_object(this_player(),
       "你找到一棵「三珠树」(tree)，摇摇(shake)它说不定会有什麽东西掉下来。\n");
    be_search=1;       
    set("c_item_desc",([
          "tree":
"       这是一棵光明灿烂的树，这树的形状有点像柏树，树叶都是些\n"
"       明亮的珍珠，从树身的两旁对称地生出两枝树干，和主干并而\n"
"       为三，远远望去，有点像彗星的尾巴。\n"
    ]) );                     
    return 1;
}
int do_shake(string arg)
{ 
    object fruit;
    if (!arg || arg!="tree") return 0;
    if (!be_search) return 0;
    if (be_dig) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    be_dig=1;
    this_player()->delete_temp("mobs");
    tell_object(this_player(),
        "你用力摇「三珠树」，结果，从树叶掉下一颗红色的果实！\n");
    fruit=new(LITEM"fruit");
    fruit->move(this_object());
    delete("c_item_desc/tree");
    call_out("do_recover",300);
    return 1;
}
void do_recover()
{
    be_search=0;
    be_dig=0;
}
void reset()
{
    be_search=0;
    be_dig=0;
    delete("c_item_desc/tree");
    ::reset();
 }