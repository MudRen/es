#include "../island.h"

inherit ROOM;

void create()
{
     object knight;
     ::create();
     
     set_short("史迹陈列室");
     set_long(@C_LONG
这儿就是和平纪念堂的二楼，这儿供奉著促成和平者『圣骑士』的金
身，还有专人在维护金身的安全与完整。只见堂中弥漫著一股庄严肃穆的
气氛，进入此处，最好保持严肃的心情，不然你可能会很快就会遭到报应
哦！
C_LONG
             );
     set("light",1);
     set("exits",([
                 "down" : ITOWN"museum"
            ]) );
     set("objects",([
           "monk": IMON"e-shi",
           "trashcan" : "/obj/trashcan"
          ]) );
     set("no_embattle",1);
     set("no_demand",1);
     knight=new(IMON"holy_knight");
     knight->move(this_object());     
     reset();
 }

int clean_up() { return 0; } 