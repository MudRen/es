//File: book_temple2.c 少林寺藏经楼

#include "saulin_temple.h"

inherit ROOM;

int pull=0;

void create()
{
       ::create();
       set_short("少林寺藏经楼");
       set_long( @C_LONG_DESC
你走进向往已久的藏经阁，阁内寂寂无声，四面墙壁都是直抵屋顶的书架，
每一格架上都贴了一张小条，上面写的是弯弯曲曲的怪字，想必是梵文，看来
想从这个浩瀚书海中找到少林寺的武功\密笈真是难上加难。右方书架正中有两
扇长窗(windows)，可是却没有光线射进来，想必是被书籍给堵死了。
C_LONG_DESC
       );
	   set("light",1);
	set("objects",([ "monk" : SAULIN_MONSTER"shu_ju" ,]));
       set("exits",([
         "out" : SAULIN"book_temple1",
       ]) );
       reset();
       set("item_desc",([ "windows":
@C_LONG
    这是两扇长木窗，虽然被擦拭的很乾净，但是却没有光线透进来。
C_LONG
       ]));
}

void init()
{
     add_action("pull_window","pull");
     add_action("climb_ladder","climb");
}

int pull_window(string str)
{
    if( !str || str != "windows" )
       return notify_fail(can_read_chinese()?
         "你要拉什麽?\n" :
         "What do you want to pull ?\n" );
if (present("shu ju",this_object()))
{
    tell_object(this_player(), can_read_chinese() ? @C_OPEN
你正想用力把窗子拉开，虚竹走了过来阻止你，他合十道：为了本阁藏书
的保存，这个窗子是开不得的，请不要把它打开。
C_OPEN
: "You want to pull the window but shu ju stop you.\n"
    );
	return 1;
}

    tell_object(this_player(),@C_LONG
你用力把窗子一拉，整面窗子突然向你移动过来，现出书架後的一架木梯
，木梯很乾净，好像常有人出入，或许\你可以爬(climb)上去看看。
C_LONG
    );
    pull = 1;
    return 1;
}
                   
int climb_ladder(string str)
{
      if( !str || str != "ladder" || !pull )
        return notify_fail("你要爬什麽?\n");
       this_player()->move_player(SAULIN"book_temple3");
       return 1;
}
