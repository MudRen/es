#include "../../story.h"

inherit SPALACE"RR";
void create()
{
        ::create();
	set_short("天都大殿");
	set_long( @LONG
你正立足在天都大殿的中心。大殿地面原是用整片翠精碧玉建成的，玉质特佳
，光明若镜，毛发可鉴。环顾殿内，琉璃天瓦，上下两相对照，发出七彩旋转虹光
；殿中一金鼎，刻画著山精海怪，张牙舞爪，各式各样，不怪不出，无奇不有，与
整个格局显得格格不入，诡异已极。另外在殿中还有块白色的石头(stone)。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e1",
           "west" : SPALACE"w1",
          "north" : SPALACE"n1",
          "south" : SPALACE"s1",
        ]) );
	set( "c_item_desc", ([
	  "stone" : @LONG
一颗有著纯白色的石头，石头上写著白色代表主要的意思，上面有被摸过(touch)的痕迹。

LONG
	]) );
	reset();
}
void init()
{
   add_action("do_touch","touch");
   ::init();
}
int do_touch(string arg)
{
    if ( !arg || arg !="stone" ) 
       return notify_fail("你要摸什麽东西？\n");
    write("\n\n你好奇地摸一摸这块白色的石头，只见一道白色的光线贯穿你的身子！\n\n\n\n\n");
    this_player()->move_player("/d/noden/14,9.noden",({
         "%s的身子被一道白色的光线贯穿！\n",
         "%s借著一道白色来到了这里.\n"}),"");
    write("\n在白光之後，你被带到了主大陆。\n");
    return 1;
}