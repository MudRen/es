
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("内城入口");
        set_light(1);
        set_long( @LONG_DESCRIPTION
和一般的城不一样的是，天空之城是整个飘浮在天空中的，身处在云雾
之间，让你感到有如到了仙境。你仔细往四周瞧瞧，这才发现鸟人族的人民
大部份都是在天上飞来飞去，鲜少有在地上活动的，原来天空之城的内城才
是鸟人族主要的活动区，外城则是为防范敌人而建。
    抬头向上望，内城正在你的头顶上飘啊飘的。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "west" : HAWK"room1-10",
        "north" : HAWK"room1-8",
        "up" : HAWK"room2-15",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" || str=="up" )
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
