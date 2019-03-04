
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("城门检查哨");
        set_light(1);
        set_long( @LONG_DESCRIPTION
你看到一个戒备森严的警备哨，一堆鸟头人身，长著宽阔翅膀，脚上有著
老鹰般的利爪的战士正上下打量著你，看来你想要通过这边不是件简单的事。
LONG_DESCRIPTION
        );
        set("objects", ([
                "war" : MOB"warrior",
                "war1" : MOB"warrior",
                "mage" : MOB"mage" ]) );
        set( "exits", ([
        "west" : HAWK"room1-8",
        "northeast" : HAWK"room1-6",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="northeast" )
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
