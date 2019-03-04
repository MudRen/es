#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("蜥蜴人领事馆");
     set_long(@C_LONG
这儿是蜥蜴人的驻外办事处，在此设办事处的主要目的是为了增进该
族与外界的联系，协助有意开发其生活区的发展；但是，最主要的目的不
外乎是想利用这儿丰富的资讯来侦查魔族及武士堡的最新动态！
C_LONG
             );
     set("light",1);
     set("exits",([
               "north"  : ITOWN"square06"
            ]) );
     set("objects",([
               "lady"  : IMON"lady" ]) );
     reset();
#include <replace_room.h>
 }