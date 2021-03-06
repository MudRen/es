#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
啊！毒气，糟糕，你走进了最危险的沼泽地，四周都是足以致命的瘴气。但是
奇怪的是，这里不像其他沼泽地充满各式各样吃人的巨型怪物，也没有人类的□骨
，相反的，这里到处都是巨型沼泽怪兽的残骸；虽然你已经站在这里好一段时间，
但却没有任何一只怪物追来。你四下搜寻，发现西边的空气中弥漫著一股浓厚的血
腥恶臭，这股恶臭比沼气更刺鼻，更难闻，而且每隔一段时间就传来一阵怪啸，声
音有如牛哞，但却远比其响亮。你想，一定是更恐怖的怪物。啊，你一声惨叫，原
来是一只毒蛾散下的磷粉弄痛了你的双眼，你慌慌张张的用力把它踹开，但四周愈
来愈多奇奇怪怪的生物靠了过来，你现在脑中只有一个想法，就是『逃命啊』！
LONG
    );
    set( "exit_suppress", ({
            "east","north","west" }) );
    set("exits",([
            "east":LAKE"swamp3",
            "north":LAKE"swamp4",
            "west":LAKE"swamp6"
       ]) );
    set("objects",([
         "moth#1":LMONSTER"moth",
         "moth#2":LMONSTER"moth",
         "moth#3":LMONSTER"moth"
    ]) );
    reset();
}

