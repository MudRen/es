
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("内城小径");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
远离了内城大道的喧嚣和军事紧张的气氛，这里是天空之城最安静的地
方之一，许多年青的鸟人们，在一天紧张的生活之中，常会忙里偷闲的到这
边闲晃，不过，要是天雨路滑，你就要小心罗，从这要是往外掉，可是会摔
的不轻喔。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northeast" : HAWK"room2-8",
        "south" : HAWK"room2-5",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="northeast" || str=="south" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(90);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}
