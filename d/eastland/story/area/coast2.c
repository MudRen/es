#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("沙滩");
	set_long( @LONG
你现在来到了一处平坦的白沙滩，西边是一望无际的大海，有大海上有几块秃
出海面的礁石，头顶是炙热的□阳和一抹无垠的青空。波浪慢条斯理地拍打著沙岸
，溅起些许水花；海风徐徐轻拂著你的脸颊，吹散了周遭炙窒的热气，四肢百骇彷
佛感受到它的恩惠，扫尽了酷署的日照；沙滩上各式贝类星罗棋布或游走著小螃蟹
；海里头穿梭著五彩斑斓的鱼儿。徜徉在这一片白沙滩里，顿时感到烦恼尽失，使
你不再想到任何杀伐争执。
LONG
	);
        set("light",1);
	set("exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast1",
        ]) );
	set("objects", ([
	  "crab#1" : SMOB"crab1",
          "crab#2" : SMOB"crab2",
          "crab#3" : SMOB"crab3",
          "crab#4" : SMOB"crab4",
	]) );
        set( "c_item_desc" ,([
          "礁石" : "几块秃出海平面的岩石，你可以沿海岸游 ( swim ) 过去。\n"        
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_swim","swim");
}
int do_search( string arg )
{
   write("你发现海面上有几块秃出的礁石，如果你游技好可以游过去( swim )！\n");
   return 1;   
}
int do_swim( string arg )
{
   object player;
   string c_name;
   player=this_player();  
   c_name=player -> query("c_name");
   tell_object(player,
      "你沿著海岸往不远处的礁石游过去．．\n");
   tell_room(this_object(),sprintf(
      "%s沿著海岸往不远处的礁石游过去．．\n",c_name),player);
   player->move_player(SAREA"stone1","SNEAK");
   return 1;
}