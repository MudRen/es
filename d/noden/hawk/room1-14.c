
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("贫民窟");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
越往贫民窟里走，越觉得有一股死亡的气息弥漫在四周，对未来的绝望
和对过去的缅怀使得这些居住在贫民窟的鸟人们越来越不满。你发现到路旁
有一间破破的小屋，相对之下算是满乾净的，你想要进去看看吗?
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-15",
        "northwest" : HAWK"room1-13",
           ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter" ,"enter");
}

int to_enter(string s)
{
        if ( s!= "house") return 0;
        this_player()->move_player(HAWK"room1-20","SNEAK");
        return 1;
}

