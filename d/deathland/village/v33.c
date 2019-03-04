
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The flying room","飘浮之屋");
    set_long(@Long
Long
,@CLong
一间简简单单的房屋,但是最奇怪的是它没有门,四边的墙壁都是落地窗,除此之外房子
的中间有一张书桌,而书桌的上面\摆\设著一颗水晶球(crystalball),除此之外并没有其它的
东西了.
    有一个楼梯通向楼上的一间小房间,似乎是长老的休息室.
CLong
    );
    set("c_item_desc",([
        "crystalball":"一颗神秘的水晶球.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/vr9",
             ]));
    ::reset();
}

void init()
{
     add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str|| (str!="crystalball"&&str!="ball")) return 0;
    else 
      {
        write("一股寒意涌上了你的心头,忽然一阵柔和的光线笼罩著你,你的人忽然被传送置别处了.\n");
        this_player()->move_player(Deathland"/village/v32",
         ({"%s被传送走了.\n",
         "%s伴随著一阵光出现在这里.\n"}) );
        return 1;  
      }
}  
   
