#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼三楼" );
   set_long(@ANGEL
在你来到千川楼三楼，这千川楼最高的地方，同时也是武士团队长约修的住
所，但也是最安静的地方，在这里你找不到任何一个守卫，似乎约修对於下面两
楼的守卫相当有自信，空气中还飘有一股黑檀木的香气．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "down"  :MR"inn2-6",    
    "north" :MR"inn3-2",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

