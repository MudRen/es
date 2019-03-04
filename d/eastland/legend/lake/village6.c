#include "../legend.h"

inherit ROOM;

void create()
{
object kun;    
        ::create();
    set_short("月到风来亭");
        set_long( 
@LONG
一座古色古香的六角亭。斜□飞檐，结构巧妙，名为『月到风来』亭，不论是
取名，或是建筑构造，在海内堪称独步。凉亭边一块大石旁种有一本『眼儿媚』，
掩掩映映，更添姿色。
LONG
    );
    set( "light",1);
    set("exits",([
          "out":LAKE"village4",
    ]) );
    kun = new(LMONSTER"pao_kun");
    kun->move(this_object());
                
    reset();
}
int clean_up()
{
    return 0;
}