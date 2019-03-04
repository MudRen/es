#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龙宫大殿" );
	set_long(
@LONG_DESCRIPTION
这是井龙宫的大殿，虽然不大但仍有一股气势在，这里比起陆上皇帝的宫殿
不知华丽几千倍，文臣武将列在两旁，他们正以一种奇怪的眼神看著你，往
前望去，似乎有人高高的坐在上面。
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"palace1",
	     "north" : OTEMP"palace3",
	]) );
        set ("objects", ([
             "fish_scholar":OMONSTER"fish_scholar",
             "fish_general":OMONSTER"fish_general",
             ]) );
        set("light",1);
        reset();
}
