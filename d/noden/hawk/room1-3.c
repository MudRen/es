
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("秘密小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你吓然发现到在那绝壁之後，竟隐藏有这麽一条小径，你不禁赞叹
起造出此一秘密小径的生物。不过奇怪的是，小径造得相当粗糙，让你
走起来觉得颇不舒服，不知道是为了什麽。此外，这条位在峭壁边的小
径也不宽敞，最好是注意一下你的脚步，掉到山下可不是一件好玩的事
唷！
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-4",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" )
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
