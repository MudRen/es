#include "goomay.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  set_short("废弃的地道");
  set_long(@Long
这是一处非常破旧的地方，充满了蜘蛛网和灰尘，地道中央摆\了一张
方桌和几张躺椅，也许\这里原来是间休息室，而在其中一张椅子上有一具
骨骸(skeleton)躺在那里。
Long
);

set("item_desc",([
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );
set( "objects", ([
	"rat1" : Mob"salamander",
	"rat2" : Mob"salamander", ]) );

set("exits",([
     "north"	:  Goomay"cellar2",
     ]) );

 reset();
}

void reset()
{
   ::reset();
   letter=0;
}

string to_look_skeleton()
{
   switch(letter) {
   case 0:
   return "它是一副高大修长的骨骸，由大小来判断应该是精灵或半精灵的骨骸，\n"+
		"在他的手上似乎握著一个东西。\n";
   case 1:
   return "一个高大修长的骨骸，由大小来判断应该是精灵或半精灵的骨骸。\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Obj"letter01");
     ob1->move(this_player());
     return "你从骨骸的手中发现了一张发黄的羊皮纸。\n";
   case 1:
     return "在一阵仔细的搜索下,你只能判定这是个精灵的骨骸。\n"; 
   }  
}
