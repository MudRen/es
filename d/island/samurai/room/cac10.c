#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "中央广场" );
   set_long(@ANGEL
在你的面前是一个宽大的大广场，其位置可说是此城堡的中央，向西
可以前往武士训练场，向东则可以前往市场，而往北一直走下去可以到武
士指挥中心～千川楼～．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");
	set( "objects",([
    "citizen1" :MOB"citizen",
    "citizen2" :MOB"citizen"
           ]) );			
        set( "exits", ([
    "west"  :MR"cac05",    
    "north" :MR"cac09"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

