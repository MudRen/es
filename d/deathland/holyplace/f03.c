// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("mystic cave","神秘的洞穴");
    set_long(@Long
Long
,@CLong
一处阴暗的地方, 整个洞穴没有什麽特别的, 除了一个小小的木门 .
CLong
);

set("item_func",([
    "door":"to_look_door",
    "description":"to_look_description",
    ]) );
set("exits",([
             "out":Deathland"/holyplace/f02",
             ]));
reset();
}

void init()
{
     add_action("to_smash","smash");
}
int to_look_door()
{
     write( can_read_chinese() ?
            "一个小小的木门. 门上似乎有一段文字(description)写在上面. \n"
            "除此之外, 你发现门上没有把手, 似乎没有任何方法能打开这门,\n"
            "除非你用撞(smash)的.\n":
            "need work.\n");
     return 1;        
}

int to_look_description()
{
    write( can_read_chinese() ?
          "通往死亡的入口.\n"
          :
          "A entrance toward Death.\n"
          );
    return 1;      
}

int to_smash(string str)
{
    if (!str ||str!="door") return 0;
    write("当你撞上那门的时候, 忽然整个门消失了, 而你也跌进了另一个地方.\n");
    this_player()->move_player(Deathland"/holyplace/f04",({
    "%s disappear.\n","你只见%s穿过木门消失了.\n",
    "%s enters.\n","%s跌了进来.\n",}) );
    return 1;
}
