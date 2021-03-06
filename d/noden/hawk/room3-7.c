
#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("神秘的房间");
        set("light",1);
        set_long( @LONG_DESCRIPTION
你走进这一间房间，映在你眼前的，除了白色，还是白色。彷佛空无一物，
又彷佛充满了许多感受不到的奇妙物质。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northeast" : HAWK"room3-8",
                "southeast" : HAWK"room3-9",
                "west" : HAWK"room3-1",
                     ]) );
        create_door("west","east",([
                "keyword":({"whitedoor","door"}),
                "status":"closed",
                "c_desc":"一个白色的小门",
                "c_name":"白玉门",
                "name":"white jade door",
                "desc":"a white jade door",
        ]) );
    reset();

}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str =="west" || str=="southeast" || str=="northeast" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}
