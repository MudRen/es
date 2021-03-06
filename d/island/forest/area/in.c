#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("瀑布内侧");
    set_long(@LONG
原来瀑布後头还有一点点可以容身的地方，经年累月的冲蚀使得岩石变
得光滑，而且长满了苔藓；你可以确信的是，这地方似乎不是天然形成的。
LONG
            );
    set("light",1);
    set_outside("island");
    reset();
}

void init()
{
    add_action("do_search","search");
    add_action("do_climb","climb");
}

int do_search()
{
      tell_object(this_player(),
      "嗯～～！根据你推断的结果，确信这里有攀爬(climb)过的痕迹.......\n");
      return 1;
}

int do_climb( string arg)
{
    if( !arg || arg=="" )
      return notify_fail("你要爬哪个方向呢？\n");
    if( arg != "up")
      return notify_fail("这里就是瀑布的下方了，你还想往哪儿爬呢？\n");
    to_climb_up(this_player(),AREA"in1",40);
    return 1;
}
