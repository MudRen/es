#include "iigima.h"
inherit ROOM;

void create()
{

        ::create();
        set_short( "hilove temple","希鲁芙神殿");
        set_long(
        @C_LONG
广大的空间，挑高有３０米吧，你看了不禁为黑暗精灵族的建筑技术
感到讶异，这里是黑暗精灵村落四大神殿中最大的一间，四周灯火通明，
墙上雕有很多的蜘蛛图案，而中央的大平台上，有一尊很大的神像
(statue)，祥和而安宁的模样，似乎不是黑暗精灵所供奉的邪神。
墙边的蜘蛛图案上有一个板手(lever)，似乎怪怪的。
C_LONG
        );

        set( "light",0 );
        set( "exits", ([

                     "east": DROW"r18",
        ]) );
        set("search_desc",([
                   "lever": "@@to_search_lever"
          ]) );
        set("c_item_desc",(["statue":

@C_LONG
这是黑暗精灵膜拜的风之女神－希鲁芙的雕像，开展的双翼弯曲
地遮住了半个神殿的面积，看来栩栩如生的样子。
C_LONG
,
            "lever":
@C_LONG
这个板手斜插入一个小小黑黑的螺孔内，看来是某个通道的机
关吧。
C_LONG
           ]));
        set("objects", ([
              "m7": DRO"chim"
        ]) );
        reset();
}
int to_search_lever()
{
     write("哇～你感到一阵天旋地转，好像来到另一个地方了。\n");
     this_player()->move_player(DROW"r26","SNEAK");
     return 1;
}
