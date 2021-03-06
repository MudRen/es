
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The road of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村庄的环庄道路上,这里有著非常和平安详的气氛,恍佛是一个世
外桃源.这里已经多年没有战争了,矮人们的童年几乎在此渡过. 西边的建筑是你在矮人
度里看过最华丽,最优美的建筑,但是似乎有股魔力阻挡你进入.
CLong
    );
    set("exits",([
                "west":Deathland"/village/vr7",
                "north":Deathland"/village/v15",
                "south":Deathland"/village/v13",
             ]));
    set("pre_exit_func",([
                "west":"to_pass",
                ]) );
    set("objects",([
        "bard":Monster"/bard02",
         ]) );
    ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("deathland_magicwall")) ) {
     write("一道魔法墙阻挡住你的去向.\n");
     return 1;
     }
   else {
     write("由於你的身体有著一股神奇的力量,你轻易的通过魔法墙.\n");
     return 0;
     }   
}
