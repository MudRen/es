
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("天空之城城门");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到这里，你以经可以清楚的看到天空之城高大的大门口了。你仔细端详
著大门，发现竟是由最名贵的大理石所建，上面雕满了许多飞禽走兽的图样，
真不知道这些共花费了多少人力才完成。往城门内一看，你发现到整个城其实
是浮在空中的，这时候你终於相信传说中的天空之城是存在的。此外你也看到
了许多鸟人在城内飞来飞去，看来这个与世隔绝已久的城市大概可以说是鸟人
族的世外桃源。为预防敌人的入侵，在这里也有数名鸟人族的战士驻守。
LONG_DESCRIPTION
        );
        set("objects", ([
                "war" : MOB"fighter",
                "war1" : MOB"fighter"]) );

        set( "exits", ([
        "east" : HAWK"room1-7",
        "south" : HAWK"room1-9",
                    ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="east" )
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
