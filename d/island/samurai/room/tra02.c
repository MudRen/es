#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士训练场" );
   set_long(@ANGEL
你现在正在武士训练场内，四周摆了好几根击剑用的木头，还有几把练
习用的木刀摆在一旁，一股浓浓的汗臭味刺激著你的鼻子，墙上挂著一幅字
画(picture)．　
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "east" :MR"tra01",
    "west" :MR"tra04",
    "south":MR"tra03",
    "north":MR"tra07"
                ]) );
      create_door("east","west",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "木门",
                  "c_desc"  : "一个木头做的门\n"
                  ]) );
     set("c_item_desc",(["picture":@AAA
     你可以看到上面用著苍建有力毛笔写著:
     
     武士之道，永无止境
     
AAA
]));                            
         reset();                     
}

