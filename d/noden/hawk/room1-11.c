//room1-11.c
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("外城小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
    走在外城的小径上，远眺著你刚刚走来的小径，回想起刚刚步步惊
魂的情景，以及那蜿蜒崎岖的山路，你觉得似乎很难会有敌人能够入侵
吧，不知道鸟人们在怕些什麽，问问这里的老人们或许可以得到一些消
息吧。往西走就可以到达士兵们居住的军营，你可以看到三五成群的士
兵们在这附近巡逻著。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "soldier1" : MOB"warrior",
                "soldier2" : MOB"warrior",
                "soldier3" : MOB"warrior"
                        ]) );
        set( "exits", ([
        "west" : HAWK"room1-12",
        "north" : HAWK"room1-10",
                ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}
