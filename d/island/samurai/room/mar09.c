#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "旅店" );
   set_long(@ANGEL
这里是一间不起眼的旅店，昏暗的灯光和老旧的家具，让你怀疑
这种店怎麽会有人来住．　
ANGEL

   
         );
	set( "light",1);		
	set( "objects",([
	"fan":MOB"fan"
	]));
        set( "exits", ([
    "up":MR"mar10",    
    "south" :MR"mar08"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

