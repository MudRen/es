
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("竞技场");
        set_long( @LONG_DESCRIPTION
这里是鸟人族每年比武大会举行的地点，你可以看到四周空荡荡的啥都
没有，正是比武的好地方。不过，你却发现现在有点不一样，观察一下，你
似乎觉得四周隐隐约约传来野兽的咆啸及低声嘶吼的声音，看来，你得要自
求多福罗。如果想要回头的话，这里有条粗粗的绳索(rope)可以让你往上爬
(climb) 。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"square2",
        "south" : HAWK"square4",
                     ]) );
    reset();
}//end of creat


void init()
{
        add_action("to_climb","climb");
}

int to_climb(string str)
{
        if ( !str || str != "rope") return 0;
        tell_object(this_player(),@LONG
你沿著绳索慢慢往上爬。
LONG
        );
        this_player()->move_player(HAWK"room3-4","SNEAK");
        return 1;
}
