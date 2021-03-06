
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("秘密小径");
        set_light(1);
        set_long( @LONG_DESCRIPTION
小路继续沿伸著，而且弯弯曲曲颇不好走，从远方渐渐传来山岚的
呼啸声，还隐隐约约彷佛可以听到几声凄厉的鸟叫声，不过因为距离的
关系，你无法分辨出是什麽声音。再次提醒你，要注意脚边，否则摔入
悬崖之下不死也是去掉半条命喔。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-5",
        "northwest" : HAWK"room1-3",
                        ]) );
        set("objects", ([
                "bug" : MOB"bird"
                        ]) );

    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" || str =="northwest")
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
