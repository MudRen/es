#include "forest.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("森林的深处");
        set_long( @C_LONG_DESCRIPTION
这里是猛兽森林的深处，树木非常地茂盛，连阳光都无法进入，因此也
显得格外的阴森。当你向四周围望去，你发现黑暗中有无数双碧□闪烁的眼
睛正邪恶地注视著你，要不是为了寻找传说中的灵兽，谁也不会愿意到这种
鬼地方来的。
C_LONG_DESCRIPTION
 );

        set( "exits", ([
                 "north"       : Forest"4,2.forest",
                 "east"        : Forest"5,1.forest",       
                 "west"        : Forest"3,1.forest",
            ]) );
                      
        set("objects", ([ 
                  "tiger#0" : FORMOB"tiger",
                  "tiger#1" : FORMOB"tiger",
            ]) );
            
        reset();    
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#8");
}
