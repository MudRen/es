#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼大门" );
   set_long(@ANGEL
在你的面前是武士城堡的指挥中心千川楼的入口，整个大楼有个很浓厚
的日本式风味，你还可以闻到一股黑檀木的香味，似乎千川楼用了\许\多的黑
檀木为建材，在大楼的四周种了两排的樱花树，使的整间大楼看起来好像在
树林里一样．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2",
	        "guard2":MOB"guard2",
	        ]) );
        set( "exits", ([
    "south" :MR"inn02",
    "north" :MR"inn04",
    "west"  :MR"tree01"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "黑檀木门",
                  "c_desc"  : "一个用黑檀木做门，上面用精细的手工\n"
                              "雕出一条华丽的龙\n"
                  ]) );
                            
         reset();                     
}

