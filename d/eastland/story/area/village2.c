#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("村庄道路");
	set_long(@LONG
你来到了一处羽民族居住的村庄道路上，西边是一排排的小屋，南边是大树群
。由於这村落置身在一大片树丛里，显得格外神秘又隐敝，好似一座天然的住处。
另外在道路上种植了许多葡萄树，树上的果实平时供羽民族食物，而果实中的液汁
也是羽民族赖以为生的水源。这村落由於没什麽活动的空间，小孩子们都会跑到村
外的草原去游玩，但大人们都深以为忧，恐怕这里被人发现。东边是羽民族大首领
居住的地方。另外在路旁有座大石雕，雕刻著羽民族传说中的英雄，你可以向它膜
拜(worship)祈求它赐予你力量与勇气。另外在在石雕旁还有块黄色大石(stone)。

LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house3",
                "west" : SAREA"house4",
               "north" : SAREA"village1",
        ]) );
        set("objects", ([
               "stone" : SITEM"statue1"
        ]) );
        set( "c_item_desc", ([
               "stone" : @LONG
一颗有著纯黄色的大石，黄色代表著东方和平的象徵，上面有被摸过(touch)的痕迹。
LONG
        ]) );
	reset();
}
void init()
{
     add_action("do_worship","worship");
     add_action("do_touch","touch"); 
}
int do_touch(string arg)
{
   if ( !arg || arg !="stone" )
       return notify_fail("你要摸什麽东西？\n");
   write("\n你好奇地摸一摸这块黄色的大石，只见一道黄色的光线贯穿你的身子！\n\n\n
");
   this_player()->move_player("/d/eastland/8,5.east",({
      "%s的身子被一道黄色的光线贯穿！\n",
      "%s借著一道黄色来到了这里.\n"}),"");
   write("\n在黄光之後，你被带到了东方大陆。\n");
   return 1;
}
int do_worship()
{
     tell_object(this_player(),
        "你双手合什，向雕像的神像膜拜，你感觉到全身似乎充满了力量！\n");
     this_player()->save_me();
        "/adm/daemons/backup"->user_backup(this_player());
     return 1;
}