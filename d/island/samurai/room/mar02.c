#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "市场" );
   set_long(@ANGEL
这里有许多人们聚集在此买卖物品，这就是武士城堡内的市场，虽说
这是武士堡内最热闹的地方，但是所卖的物品却少的可怜，你如果想买一
些有用的东西，劝你还是别来这里吧！
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar03",    
    "west" :MR"mar01",
    "east" :MR"mar08",
    "south":MR"mar04"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

